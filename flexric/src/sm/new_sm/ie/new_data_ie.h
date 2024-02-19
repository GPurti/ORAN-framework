/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

#ifndef NEW_DATA_INFORMATION_ELEMENTS_H
#define NEW_DATA_INFORMATION_ELEMENTS_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * 9 Information Elements (IE) , RIC Event Trigger Definition, RIC Action Definition, RIC Indication Header, RIC Indication Message, RIC Call Process ID, RIC Control Header, RIC Control Message, RIC Control Outcome and RAN Function Definition defined by ORAN-WG3.E2SM-v01.00.00 at Section 5
 */

#include <stdbool.h>
#include <stdint.h>

//////////////////////////////////////
// RIC Event Trigger Definition
/////////////////////////////////////

typedef struct {
  uint32_t ms;
} new_event_trigger_t;

void free_new_event_trigger(new_event_trigger_t* src); 

new_event_trigger_t cp_new_event_trigger( new_event_trigger_t* src);

bool eq_new_event_trigger(new_event_trigger_t* m0, new_event_trigger_t* m1);



//////////////////////////////////////
// RIC Action Definition 
/////////////////////////////////////

typedef struct {
  uint32_t dummy;  
} new_action_def_t;

void free_new_action_def(new_action_def_t* src); 

new_action_def_t cp_new_action_def(new_action_def_t* src);

bool eq_new_action_def(new_event_trigger_t* m0,  new_event_trigger_t* m1);



//////////////////////////////////////
// RIC Indication Header 
/////////////////////////////////////

typedef struct{
  uint32_t dummy;  
} new_ind_hdr_t;

void free_new_ind_hdr(new_ind_hdr_t* src); 

new_ind_hdr_t cp_new_ind_hdr(new_ind_hdr_t const* src);

bool eq_new_ind_hdr(new_ind_hdr_t* m0, new_ind_hdr_t* m1);


//////////////////////////////////////
// RIC Indication Message 
/////////////////////////////////////

// We want to get 4 data coming from ngu_tunnel from RAN
typedef struct
{
  uint64_t data1;
  uint64_t data2;
  uint64_t data3;
  uint64_t data4;
} new_ng_u_tunnel_stats_t;

typedef struct {
  new_ng_u_tunnel_stats_t* ngut;
  uint32_t len; // define Length for our ngut array

  int64_t tstamp; // Time stamp to trace latency of flexRIC
} new_ind_msg_t; // Serivce model indication message

// Supporting function
void free_new_ind_msg(new_ind_msg_t* src); 

new_ind_msg_t cp_new_ind_msg(new_ind_msg_t const* src);

bool eq_new_ind_msg(new_ind_msg_t* m0, new_ind_msg_t* m1);

//////////////////////////////////////
// RIC Call Process ID 
/////////////////////////////////////

typedef struct {
  uint32_t dummy;
} new_call_proc_id_t;

void free_new_call_proc_id( new_call_proc_id_t* src); 

new_call_proc_id_t cp_new_call_proc_id( new_call_proc_id_t* src);

bool eq_new_call_proc_id(new_call_proc_id_t* m0, new_call_proc_id_t* m1);



//////////////////////////////////////
// RIC Control Header 
/////////////////////////////////////


typedef struct {
  uint32_t dummy;
} new_ctrl_hdr_t;

void free_new_ctrl_hdr( new_ctrl_hdr_t* src); 

new_ctrl_hdr_t cp_new_ctrl_hdr(new_ctrl_hdr_t* src);

bool eq_new_ctrl_hdr(new_ctrl_hdr_t* m0, new_ctrl_hdr_t* m1);



//////////////////////////////////////
// RIC Control Message 
/////////////////////////////////////


typedef struct {
  uint32_t action;
} new_ctrl_msg_t;

void free_new_ctrl_msg( new_ctrl_msg_t* src); 

new_ctrl_msg_t cp_new_ctrl_msg(new_ctrl_msg_t* src);

bool eq_new_ctrl_msg(new_ctrl_msg_t* m0, new_ctrl_msg_t* m1);



//////////////////////////////////////
// RIC Control Outcome 
/////////////////////////////////////

typedef enum{
  NEW_CTRL_OUT_OK,

  NEW_CTRL_OUT_END
} new_ctrl_out_e;


typedef struct {
  new_ctrl_out_e ans;
} new_ctrl_out_t;

void free_new_ctrl_out(new_ctrl_out_t* src); 

new_ctrl_out_t cp_new_ctrl_out(new_ctrl_out_t* src);

bool eq_new_ctrl_out(new_ctrl_out_t* m0, new_ctrl_out_t* m1);


//////////////////////////////////////
// RAN Function Definition 
/////////////////////////////////////

typedef struct {
  uint32_t dummy;
} new_func_def_t;

void free_new_func_def( new_func_def_t* src); 

new_func_def_t cp_new_func_def(new_func_def_t* src);

bool eq_new_func_def(new_func_def_t* m0, new_func_def_t* m1);

/////////////////////////////////////////////////
//////////////////////////////////////////////////
/////////////////////////////////////////////////


/*
 * O-RAN defined 5 Procedures: RIC Subscription, RIC Indication, RIC Control, E2 Setup and RIC Service Update 
 * */


///////////////
/// RIC Subscription
///////////////

typedef struct{
  new_event_trigger_t et; 
  new_action_def_t* ad;
} new_sub_data_t;

///////////////
// RIC Indication
///////////////

typedef struct{
  new_ind_hdr_t hdr;
  new_ind_msg_t msg;
  new_call_proc_id_t* proc_id;
} new_ind_data_t;

void free_new_ind_data(new_ind_data_t* ind);

new_ind_data_t cp_new_ind_data(new_ind_data_t const* src);

///////////////
// RIC Control
///////////////

typedef struct{
  new_ctrl_hdr_t hdr;
  new_ctrl_msg_t msg;
} new_ctrl_req_data_t;

typedef struct{
  new_ctrl_out_t* out;
} new_ctrl_out_data_t;

///////////////
// E2 Setup
///////////////

typedef struct{
  new_func_def_t func_def;
} new_e2_setup_data_t;

///////////////
// RIC Service Update
///////////////

typedef struct{
  new_func_def_t func_def;
} new_ric_service_update_t;


#ifdef __cplusplus
}
#endif

#endif

