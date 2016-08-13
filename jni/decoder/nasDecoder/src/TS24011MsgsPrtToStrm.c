/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.6.2-pre4, Date: 04-Apr-2013.
 */
#include "TS24011Msgs.h"
#include "rtsrc/rtPrintToStream.h"
#include "rtxsrc/rtxCommon.h"
#include "rtxsrc/rtxDiagBitTrace.h"

int asn1PrtToStrm_TS24011Msg_CPDATA (OSCTXT *pctxt, 
   const char* name, const TS24011Msg_CPDATA* pvalue)
{
   rtPrintToStreamOpenBrace (pctxt, name);

   asn1PrtToStrm_TS24011IE_CPUserData (pctxt, "cpUserData", &pvalue->cpUserData);

   rtPrintToStreamCloseBrace (pctxt);
   return 0;
}

int asn1PrtToStrm_TS24011Msg_CPERROR (OSCTXT *pctxt, 
   const char* name, const TS24011Msg_CPERROR* pvalue)
{
   rtPrintToStreamOpenBrace (pctxt, name);

   asn1PrtToStrm_TS24011IE_CPCauseValue (pctxt, "cpCause", &pvalue->cpCause);

   rtPrintToStreamCloseBrace (pctxt);
   return 0;
}

int asn1PrtToStrm_TS24011Msg_CP_PDU (OSCTXT *pctxt, 
   const char* name, const TS24011Msg_CP_PDU* pvalue)
{
   rtPrintToStreamOpenBrace (pctxt, name);

   asn1PrtToStrm_TS24007L3_L3HdrOptions (pctxt, "l3HdrOpts", &pvalue->l3HdrOpts);

   asn1PrtToStrm_TS24007L3_ProtoDiscr (pctxt, "protoDiscr", &pvalue->protoDiscr);

   rtPrintToStreamIndent (pctxt);
   rtPrintToStreamUnsigned (pctxt, "msgType", pvalue->msgType);

   rtPrintToStreamOpenBrace (pctxt, "data");

   switch (pvalue->data.t)
   {
      /* obj_CP_DATA */
      case 1:
      {
         asn1PrtToStrm_TS24011Msg_CPDATA (pctxt, "obj_CP_DATA", pvalue->data.u.obj_CP_DATA);
         break;
      }
      /* obj_CP_ACK */
      case 2:
      {
         rtPrintToStreamIndent (pctxt);
         rtxPrintToStreamNull (pctxt, "obj_CP_ACK");
         break;
      }
      /* obj_CP_ERROR */
      case 3:
      {
         asn1PrtToStrm_TS24011Msg_CPERROR (pctxt, "obj_CP_ERROR", pvalue->data.u.obj_CP_ERROR);
         break;
      }
      default:;
   }

   rtPrintToStreamCloseBrace (pctxt);

   rtPrintToStreamCloseBrace (pctxt);
   return 0;
}

int asn1PrtToStrm_TS24011Msg_RPHeader (OSCTXT *pctxt, 
   const char* name, const TS24011Msg_RPHeader* pvalue)
{
   rtPrintToStreamOpenBrace (pctxt, name);

   rtPrintToStreamIndent (pctxt);
   rtPrintToStreamUnsigned (pctxt, "spare", pvalue->spare);

   rtPrintToStreamIndent (pctxt);
   rtPrintToStreamUnsigned (pctxt, "rpMsgType", pvalue->rpMsgType);

   rtPrintToStreamIndent (pctxt);
   rtPrintToStreamUnsigned (pctxt, "rpMsgRef", pvalue->rpMsgRef);

   rtPrintToStreamCloseBrace (pctxt);
   return 0;
}

int asn1PrtToStrm_TS24011Msg_RPDataMSOriginating (OSCTXT *pctxt, 
   const char* name, const TS24011Msg_RPDataMSOriginating* pvalue)
{
   rtPrintToStreamOpenBrace (pctxt, name);

   asn1PrtToStrm_TS24011IE_RPDestinationAddress (pctxt, "destAddress", &pvalue->destAddress);

   asn1PrtToStrm_TS24011IE_RPUserData (pctxt, "userData", &pvalue->userData);

   rtPrintToStreamCloseBrace (pctxt);
   return 0;
}

int asn1PrtToStrm_TS24011Msg_RPDataMSTerminated (OSCTXT *pctxt, 
   const char* name, const TS24011Msg_RPDataMSTerminated* pvalue)
{
   rtPrintToStreamOpenBrace (pctxt, name);

   asn1PrtToStrm_TS24011IE_RPOriginatorAddress (pctxt, "origAddress", &pvalue->origAddress);

   asn1PrtToStrm_TS24011IE_RPUserData (pctxt, "userData", &pvalue->userData);

   rtPrintToStreamCloseBrace (pctxt);
   return 0;
}

int asn1PrtToStrm_TS24011Msg_RP_ACK (OSCTXT *pctxt, 
   const char* name, const TS24011Msg_RP_ACK* pvalue)
{
   rtPrintToStreamOpenBrace (pctxt, name);

   if (pvalue->m.userDataPresent) {
      asn1PrtToStrm_TS24011IE_RPUserData (pctxt, "userData", &pvalue->userData);
   }

   rtPrintToStreamCloseBrace (pctxt);
   return 0;
}

int asn1PrtToStrm_TS24011Msg_RP_ERROR (OSCTXT *pctxt, 
   const char* name, const TS24011Msg_RP_ERROR* pvalue)
{
   rtPrintToStreamOpenBrace (pctxt, name);

   asn1PrtToStrm_TS24011IE_RPCauseElem (pctxt, "rpCause", &pvalue->rpCause);

   if (pvalue->m.userDataPresent) {
      asn1PrtToStrm_TS24011IE_RPUserData (pctxt, "userData", &pvalue->userData);
   }

   rtPrintToStreamCloseBrace (pctxt);
   return 0;
}

int asn1PrtToStrm_TS24011Msg_RP_PDU (OSCTXT *pctxt, 
   const char* name, const TS24011Msg_RP_PDU* pvalue)
{
   rtPrintToStreamOpenBrace (pctxt, name);

   asn1PrtToStrm_TS24011Msg_RPHeader (pctxt, "header", &pvalue->header);

   rtPrintToStreamOpenBrace (pctxt, "infoElem");

   switch (pvalue->header.rpMsgType)
   {
      /* dataToNet */
      case 0:
      {
         asn1PrtToStrm_TS24011Msg_RPDataMSOriginating (pctxt, "dataToNet", &pvalue->infoElem.u.dataToNet);
         break;
      }
      /* dataToMS */
      case 1:
      {
         asn1PrtToStrm_TS24011Msg_RPDataMSTerminated (pctxt, "dataToMS", &pvalue->infoElem.u.dataToMS);
         break;
      }
      /* ackToNet */
      case 2:
      {
         asn1PrtToStrm_TS24011Msg_RP_ACK (pctxt, "ackToNet", &pvalue->infoElem.u.ackToNet);
         break;
      }
      /* ackToMS */
      case 3:
      {
         asn1PrtToStrm_TS24011Msg_RP_ACK (pctxt, "ackToMS", &pvalue->infoElem.u.ackToMS);
         break;
      }
      /* errorToNet */
      case 4:
      {
         asn1PrtToStrm_TS24011Msg_RP_ERROR (pctxt, "errorToNet", &pvalue->infoElem.u.errorToNet);
         break;
      }
      /* errorToMS */
      case 5:
      {
         asn1PrtToStrm_TS24011Msg_RP_ERROR (pctxt, "errorToMS", &pvalue->infoElem.u.errorToMS);
         break;
      }
      /* smma */
      case 6:
      {
         rtPrintToStreamIndent (pctxt);
         rtxPrintToStreamNull (pctxt, "smma");
         break;
      }
      default:;
   }

   rtPrintToStreamCloseBrace (pctxt);

   rtPrintToStreamCloseBrace (pctxt);
   return 0;
}

