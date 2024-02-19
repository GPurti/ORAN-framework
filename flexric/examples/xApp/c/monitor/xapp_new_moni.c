// Example in a generic xapp - xapp_new_moni.c
#include "../../../../src/xApp/e42_xapp_api.h"
#include "../../../../src/util/alg_ds/alg/defer.h"
#include "../../../../src/util/time_now_us.h"
#include "../../../../src/sm/new_sm/new_sm_id.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
//  Call back function 
// Implement what you're going to read from your service model

static
void sm_cb_new(sm_ag_if_rd_t const* rd)
{
  assert(rd != NULL);
  assert(rd->type == NEW_STATS_V0);

  int64_t now = time_now_us();

  printf("NEW ind_msg latency = %ld \n", now - rd->new_stats.msg.tstamp);
}

int main(int argc, char *argv[])
{
  // init the config of xApp
  fr_args_t args = init_fr_args(argc, argv);

  // init xApp
  init_xapp_api(&args);
  sleep(1);

  // Get the state of connection E2 nodes
  e2_node_arr_t nodes = e2_nodes_xapp_api();
  defer({ free_e2_node_arr(&nodes); });

  assert(nodes.len > 0);

  printf("Connected E2 nodes = %d\n", nodes.len);

  // new indication
  // Set the interval time of indication message
  inter_xapp_e i_3 = ms_1;
  sm_ans_xapp_t* new_handle = NULL;

  // if there is more than one E2 node connected to the RIC
  if(nodes.len > 0){
    // Create an array of with length of nodes
    new_handle = calloc( nodes.len, sizeof(sm_ans_xapp_t));
    assert(new_handle != NULL);
  }

  for (int i = 0; i < nodes.len; i++) {
    e2_node_connected_t* n = &nodes.n[i];
    for (size_t j = 0; j < n->len_rf; j++)
      printf("Registered node %d ran func id = %d \n ", i, n->ack_rf[j].id);
    // generate subscription request
    new_handle[i] = report_sm_xapp_api(&nodes.n[i].id, SM_NEW_ID, i_3, sm_cb_new);
    assert(new_handle[i].success == true);
  }

  sleep(2);


  for(int i = 0; i < nodes.len; ++i){
    // Remove the handle previously returned
    rm_report_sm_xapp_api(new_handle[i].u.handle);
  }

  if(nodes.len > 0){
    free(new_handle);    
  }

  //Stop the xApp
  while(try_stop_xapp_api() == false)
    usleep(1000);

  printf("Test xApp run SUCCESSFULLY\n");
}
