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



#ifndef PROVA_ENCRYPTIOIN_ASN_H
#define PROVA_ENCRYPTIOIN_ASN_H

#include "../../../util/byte_array.h"
#include "../ie/prova_data_ie.h"

// Used for static polymorphism. 
// See prova_enc_generic.h file
typedef struct{

} prova_enc_asn_t;

byte_array_t prova_enc_event_trigger_asn(prova_event_trigger_t const* event_trigger);

byte_array_t prova_enc_action_def_asn(prova_action_def_t const*);

byte_array_t prova_enc_ind_hdr_asn(prova_ind_hdr_t const*); 

byte_array_t prova_enc_ind_msg_asn(prova_ind_msg_t const*); 

byte_array_t prova_enc_call_proc_id_asn(prova_call_proc_id_t const*); 

byte_array_t prova_enc_ctrl_hdr_asn(prova_ctrl_hdr_t const*); 

byte_array_t prova_enc_ctrl_msg_asn(prova_ctrl_msg_t const*); 

byte_array_t prova_enc_ctrl_out_asn(prova_ctrl_out_t const*); 

byte_array_t prova_enc_func_def_asn(prova_func_def_t const*);

#endif
