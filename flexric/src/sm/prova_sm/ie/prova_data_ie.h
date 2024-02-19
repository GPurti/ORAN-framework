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

#ifndef PROVA_DATA_INFORMATION_ELEMENTS_H
#define PROVA_DATA_INFORMATION_ELEMENTS_H

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
} prova_event_trigger_t;

void free_prova_event_trigger(prova_event_trigger_t* src); 

prova_event_trigger_t cp_prova_event_trigger( prova_event_trigger_t* src);

bool eq_prova_event_trigger(prova_event_trigger_t* m0, prova_event_trigger_t* m1);



//////////////////////////////////////
// RIC Action Definition 
/////////////////////////////////////

typedef struct {
  uint32_t dummy;  
} prova_action_def_t;

void free_prova_action_def(prova_action_def_t* src); 

prova_action_def_t cp_prova_action_def(prova_action_def_t* src);

bool eq_prova_action_def(prova_event_trigger_t* m0,  prova_event_trigger_t* m1);



//////////////////////////////////////
// RIC Indication Header 
/////////////////////////////////////

typedef struct{
  uint32_t dummy;  
} prova_ind_hdr_t;

void free_prova_ind_hdr(prova_ind_hdr_t* src); 

prova_ind_hdr_t cp_prova_ind_hdr(prova_ind_hdr_t const* src);

bool eq_prova_ind_hdr(prova_ind_hdr_t* m0, prova_ind_hdr_t* m1);


//////////////////////////////////////
// RIC Indication Message 
/////////////////////////////////////

typedef struct {
  /* PDU stats */
  /* TX */
  uint32_t txpdu_pkts;         /* aggregated number of transmitted PROVA PDUs */
  uint32_t txpdu_bytes;        /* aggregated amount of transmitted bytes in PROVA PDUs */
  /* TODO? */
  uint32_t txpdu_wt_ms;      /* aggregated head-of-line tx packet waiting time to be transmitted (i.e. send to the MAC layer) */
  uint32_t txpdu_dd_pkts;      /* aggregated number of dropped or discarded tx packets by PROVA */
  uint32_t txpdu_dd_bytes;     /* aggregated amount of bytes dropped or discarded tx packets by PROVA */
  uint32_t txpdu_retx_pkts;    /* aggregated number of tx pdus/pkts to be re-transmitted (only applicable to PROVA AM) */
  uint32_t txpdu_retx_bytes;   /* aggregated amount of bytes to be re-transmitted (only applicable to PROVA AM) */
  uint32_t txpdu_segmented;    /* aggregated number of segmentations */
  uint32_t txpdu_status_pkts;  /* aggregated number of tx status pdus/pkts (only applicable to PROVA AM) */
  uint32_t txpdu_status_bytes; /* aggregated amount of tx status bytes  (only applicable to PROVA AM) */
  /* TODO? */
  uint32_t txbuf_occ_bytes;    /* current tx buffer occupancy in terms of amount of bytes (average: NOT IMPLEMENTED) */
  /* TODO? */
  uint32_t txbuf_occ_pkts;     /* current tx buffer occupancy in terms of number of packets (average: NOT IMPLEMENTED) */
  /* txbuf_wd_ms: the time window for which the txbuf  occupancy value is obtained - NOT IMPLEMENTED */

  /* RX */
  uint32_t rxpdu_pkts;         /* aggregated number of received PROVA PDUs */
  uint32_t rxpdu_bytes;        /* amount of bytes received by the PROVA */
  uint32_t rxpdu_dup_pkts;     /* aggregated number of duplicate packets */
  uint32_t rxpdu_dup_bytes;    /* aggregated amount of duplicated bytes */
  uint32_t rxpdu_dd_pkts;      /* aggregated number of rx packets dropped or discarded by PROVA */
  uint32_t rxpdu_dd_bytes;     /* aggregated amount of rx bytes dropped or discarded by PROVA */
  uint32_t rxpdu_ow_pkts;      /* aggregated number of out of window received PROVA pdu */
  uint32_t rxpdu_ow_bytes;     /* aggregated number of out of window bytes received PROVA pdu */
  uint32_t rxpdu_status_pkts;  /* aggregated number of rx status pdus/pkts (only applicable to PROVA AM) */
  uint32_t rxpdu_status_bytes; /* aggregated amount of rx status bytes  (only applicable to PROVA AM) */
  /* rxpdu_rotout_ms: flag indicating rx reordering  timeout in ms - NOT IMPLEMENTED */
  /* rxpdu_potout_ms: flag indicating the poll retransmit time out in ms - NOT IMPLEMENTED */
  /* rxpdu_sptout_ms: flag indicating status prohibit timeout in ms - NOT IMPLEMENTED */
  /* TODO? */
  uint32_t rxbuf_occ_bytes;    /* current rx buffer occupancy in terms of amount of bytes (average: NOT IMPLEMENTED) */
  /* TODO? */
  uint32_t rxbuf_occ_pkts;     /* current rx buffer occupancy in terms of number of packets (average: NOT IMPLEMENTED) */

  /* SDU stats */
  /* TX */
  uint32_t txsdu_pkts;         /* number of SDUs delivered */
  uint32_t txsdu_bytes;        /* number of bytes of SDUs delivered */

  /* RX */
  uint32_t rxsdu_pkts;         /* number of SDUs received */
  uint32_t rxsdu_bytes;        /* number of bytes of SDUs received */
  uint32_t rxsdu_dd_pkts;      /* number of dropped or discarded SDUs */
  uint32_t rxsdu_dd_bytes;     /* number of bytes of SDUs dropped or discarded */

  uint32_t rnti;
  uint8_t mode;               /* 0: PROVA AM, 1: PROVA UM, 2: PROVA TM */
  uint8_t rbid;

} prova_radio_bearer_stats_t;

typedef struct {
  prova_radio_bearer_stats_t* rb; 
  uint32_t len;

  int64_t tstamp;
} prova_ind_msg_t;

void free_prova_ind_msg(prova_ind_msg_t* src); 

prova_ind_msg_t cp_prova_ind_msg(prova_ind_msg_t const* src);

bool eq_prova_ind_msg(prova_ind_msg_t* m0, prova_ind_msg_t* m1);


//////////////////////////////////////
// RIC Call Process ID 
/////////////////////////////////////

typedef struct {
  uint32_t dummy;
} prova_call_proc_id_t;

void free_prova_call_proc_id( prova_call_proc_id_t* src); 

prova_call_proc_id_t cp_prova_call_proc_id( prova_call_proc_id_t* src);

bool eq_prova_call_proc_id(prova_call_proc_id_t* m0, prova_call_proc_id_t* m1);



//////////////////////////////////////
// RIC Control Header 
/////////////////////////////////////


typedef struct {
  uint32_t dummy;
} prova_ctrl_hdr_t;

void free_prova_ctrl_hdr( prova_ctrl_hdr_t* src); 

prova_ctrl_hdr_t cp_prova_ctrl_hdr(prova_ctrl_hdr_t* src);

bool eq_prova_ctrl_hdr(prova_ctrl_hdr_t* m0, prova_ctrl_hdr_t* m1);



//////////////////////////////////////
// RIC Control Message 
/////////////////////////////////////


typedef struct {
  uint32_t action;
} prova_ctrl_msg_t;

void free_prova_ctrl_msg( prova_ctrl_msg_t* src); 

prova_ctrl_msg_t cp_prova_ctrl_msg(prova_ctrl_msg_t* src);

bool eq_prova_ctrl_msg(prova_ctrl_msg_t* m0, prova_ctrl_msg_t* m1);



//////////////////////////////////////
// RIC Control Outcome 
/////////////////////////////////////

typedef enum{
  PROVA_CTRL_OUT_OK,

  PROVA_CTRL_OUT_END
} prova_ctrl_out_e;


typedef struct {
  prova_ctrl_out_e ans;
} prova_ctrl_out_t;

void free_prova_ctrl_out(prova_ctrl_out_t* src); 

prova_ctrl_out_t cp_prova_ctrl_out(prova_ctrl_out_t* src);

bool eq_prova_ctrl_out(prova_ctrl_out_t* m0, prova_ctrl_out_t* m1);


//////////////////////////////////////
// RAN Function Definition 
/////////////////////////////////////

typedef struct {
  uint32_t dummy;
} prova_func_def_t;

void free_prova_func_def( prova_func_def_t* src); 

prova_func_def_t cp_prova_func_def(prova_func_def_t* src);

bool eq_prova_func_def(prova_func_def_t* m0, prova_func_def_t* m1);

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
  prova_event_trigger_t et; 
  prova_action_def_t* ad;
} prova_sub_data_t;

///////////////
// RIC Indication
///////////////

typedef struct{
  prova_ind_hdr_t hdr;
  prova_ind_msg_t msg;
  prova_call_proc_id_t* proc_id;
} prova_ind_data_t;

void free_prova_ind_data(prova_ind_data_t* ind);

prova_ind_data_t cp_prova_ind_data(prova_ind_data_t const* src);

///////////////
// RIC Control
///////////////

typedef struct{
  prova_ctrl_hdr_t hdr;
  prova_ctrl_msg_t msg;
} prova_ctrl_req_data_t;

typedef struct{
  prova_ctrl_out_t* out;
} prova_ctrl_out_data_t;

///////////////
// E2 Setup
///////////////

typedef struct{
  prova_func_def_t func_def;
} prova_e2_setup_data_t;

///////////////
// RIC Service Update
///////////////

typedef struct{
  prova_func_def_t func_def;
} prova_ric_service_update_t;


#ifdef __cplusplus
}
#endif

#endif

