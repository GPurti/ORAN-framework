#include "/home/guillem/flexric/src/xApp/e42_xapp_api.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    fr_args_t a = init_fr_args(argc, argv);

    init_xapp_api(&a);

    usleep(10000);

    e2_node_arr_t arr = e2_nodes_xapp_api();

    if(arr.len > 0){
        printf("RAN Func ID %d \n", arr.n[0].ack_rf[0].id);
    }

    while(try_stop_xapp_api() == false)
        usleep(1000);

    free_e2_node_arr(&arr);

    return 0;
}