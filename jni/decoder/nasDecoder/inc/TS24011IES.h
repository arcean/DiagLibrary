/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.6.2-pre4, Date: 04-Apr-2013.
 */
#ifndef TS24011IES_H
#define TS24011IES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include "rtkey.h"
#include "rtxsrc/rtxContext.h"
#include "rtsrc/asn1type.h"

#include "TS24008IES.h"

/**
 * Header file for ASN.1 module TS24011IES
 */
/**************************************************************/
/*                                                            */
/*  CPUserData                                                */
/*                                                            */
/**************************************************************/
/*
 8.1.3 Message type 
 8.1.4.1 CP-User data element 

CPUserData ::= OCTET STRING (SIZE (0..249))
*/
typedef struct EXTERN TS24011IE_CPUserData {
   OSUINT8 numocts;
   OSOCTET data[249];
} TS24011IE_CPUserData;

EXTERN int NASEnc_TS24011IE_CPUserData (OSCTXT* pctxt
   , TS24011IE_CPUserData* pvalue);

EXTERN int NASDec_TS24011IE_CPUserData (OSCTXT* pctxt
   , TS24011IE_CPUserData* pvalue);

EXTERN int asn1PrtToStrm_TS24011IE_CPUserData (OSCTXT *pctxt, 
   const char* name, const TS24011IE_CPUserData* pvalue);

EXTERN void asn1Init_TS24011IE_CPUserData (TS24011IE_CPUserData* pvalue);

/**************************************************************/
/*                                                            */
/*  RPAddress                                                 */
/*                                                            */
/**************************************************************/
/*
 8.2.2 Message type indicator (MTI) 
 8.2.5.1 Originator address element 

RPAddress ::= SEQUENCE {
   length [0] INTEGER (0..11),
   ext [1] BOOLEAN DEFAULT TRUE,
   typeOfNumber [2] INTEGER (0..7),
   numberingPlanID [3] INTEGER (0..15),
   number [4] TBCDString
}
*/
typedef struct EXTERN TS24011IE_RPAddress {
   OSUINT8 length;
   OSBOOL ext;
   OSUINT8 typeOfNumber;
   OSUINT8 numberingPlanID;
   TS24008IE_TBCDString number;
} TS24011IE_RPAddress;

EXTERN int NASEnc_TS24011IE_RPAddress (OSCTXT* pctxt
   , TS24011IE_RPAddress* pvalue);

EXTERN int NASDec_TS24011IE_RPAddress (OSCTXT* pctxt
   , TS24011IE_RPAddress* pvalue);

EXTERN int asn1PrtToStrm_TS24011IE_RPAddress (OSCTXT *pctxt, 
   const char* name, const TS24011IE_RPAddress* pvalue);

EXTERN void asn1Init_TS24011IE_RPAddress (TS24011IE_RPAddress* pvalue);

/**************************************************************/
/*                                                            */
/*  RPOriginatorAddress                                       */
/*                                                            */
/**************************************************************/
/*
RPOriginatorAddress ::= RPAddress
*/
typedef TS24011IE_RPAddress TS24011IE_RPOriginatorAddress;

EXTERN int NASEnc_TS24011IE_RPOriginatorAddress (OSCTXT* pctxt
   , TS24011IE_RPOriginatorAddress* pvalue);

EXTERN int NASDec_TS24011IE_RPOriginatorAddress (OSCTXT* pctxt
   , TS24011IE_RPOriginatorAddress* pvalue);

EXTERN int asn1PrtToStrm_TS24011IE_RPOriginatorAddress (OSCTXT *pctxt, 
   const char* name, const TS24011IE_RPOriginatorAddress* pvalue);

EXTERN void asn1Init_TS24011IE_RPOriginatorAddress (
   TS24011IE_RPOriginatorAddress* pvalue);

/**************************************************************/
/*                                                            */
/*  RPDestinationAddress                                      */
/*                                                            */
/**************************************************************/
/*
 8.2.5.2 Destination address element 

RPDestinationAddress ::= RPAddress
*/
typedef TS24011IE_RPAddress TS24011IE_RPDestinationAddress;

EXTERN int NASEnc_TS24011IE_RPDestinationAddress (OSCTXT* pctxt
   , TS24011IE_RPDestinationAddress* pvalue);

EXTERN int NASDec_TS24011IE_RPDestinationAddress (OSCTXT* pctxt
   , TS24011IE_RPDestinationAddress* pvalue);

EXTERN int asn1PrtToStrm_TS24011IE_RPDestinationAddress (OSCTXT *pctxt, 
   const char* name, const TS24011IE_RPDestinationAddress* pvalue);

EXTERN void asn1Init_TS24011IE_RPDestinationAddress (
   TS24011IE_RPDestinationAddress* pvalue);

/**************************************************************/
/*                                                            */
/*  RPUserData                                                */
/*                                                            */
/**************************************************************/
/*
 8.2.5.3 RP-User data element 

RPUserData ::= OCTET STRING (SIZE (0..233))
*/
typedef struct EXTERN TS24011IE_RPUserData {
   OSUINT8 numocts;
   OSOCTET data[233];
} TS24011IE_RPUserData;

EXTERN int NASEnc_TS24011IE_RPUserData (OSCTXT* pctxt
   , TS24011IE_RPUserData* pvalue);

EXTERN int NASDec_TS24011IE_RPUserData (OSCTXT* pctxt
   , TS24011IE_RPUserData* pvalue);

EXTERN int asn1PrtToStrm_TS24011IE_RPUserData (OSCTXT *pctxt, 
   const char* name, const TS24011IE_RPUserData* pvalue);

EXTERN void asn1Init_TS24011IE_RPUserData (TS24011IE_RPUserData* pvalue);

/**************************************************************/
/*                                                            */
/*  CPCauseValue                                              */
/*                                                            */
/**************************************************************/
/*
 8.1.4.2 CP-Cause element 

CPCauseValue ::= SEQUENCE {
   ext [0] BOOLEAN DEFAULT FALSE,
   value [1] INTEGER (0..127)
}
*/
typedef struct EXTERN TS24011IE_CPCauseValue {
   OSBOOL ext;
   OSUINT8 value;
} TS24011IE_CPCauseValue;

EXTERN int NASEnc_TS24011IE_CPCauseValue (OSCTXT* pctxt
   , TS24011IE_CPCauseValue* pvalue);

EXTERN int NASDec_TS24011IE_CPCauseValue (OSCTXT* pctxt
   , TS24011IE_CPCauseValue* pvalue);

EXTERN int asn1PrtToStrm_TS24011IE_CPCauseValue (OSCTXT *pctxt, 
   const char* name, const TS24011IE_CPCauseValue* pvalue);

EXTERN void asn1Init_TS24011IE_CPCauseValue (TS24011IE_CPCauseValue* pvalue);

/**************************************************************/
/*                                                            */
/*  RPCauseElem                                               */
/*                                                            */
/**************************************************************/
/*
 8.2.5.4 RP-Cause element 

RPCauseElem ::= SEQUENCE {
   length [0] INTEGER (1..2) DEFAULT 1,
   ext [1] BOOLEAN DEFAULT FALSE,
   causeValue [2] INTEGER (0..127),
   diagField [3] SEQUENCE (SIZE (0..1)) OF INTEGER (0..255)
}
*/
typedef struct EXTERN TS24011IE_RPCauseElem {
   OSUINT8 length;
   OSBOOL ext;
   OSUINT8 causeValue;
   struct  {
      OSUINT8 n;
      OSUINT8 elem[1];
   } diagField;
} TS24011IE_RPCauseElem;

EXTERN int NASEnc_TS24011IE_RPCauseElem (OSCTXT* pctxt
   , TS24011IE_RPCauseElem* pvalue);

EXTERN int NASDec_TS24011IE_RPCauseElem (OSCTXT* pctxt
   , TS24011IE_RPCauseElem* pvalue);

EXTERN int asn1PrtToStrm_TS24011IE_RPCauseElem (OSCTXT *pctxt, 
   const char* name, const TS24011IE_RPCauseElem* pvalue);

EXTERN void asn1Init_TS24011IE_RPCauseElem (TS24011IE_RPCauseElem* pvalue);

#ifdef __cplusplus
}
#endif

#endif
