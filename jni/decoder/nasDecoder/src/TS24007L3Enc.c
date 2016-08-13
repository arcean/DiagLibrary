/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.6.2-pre4, Date: 04-Apr-2013.
 */
#include "TS24007L3.h"
#include "rtxsrc/rtxCommon.h"
#include "rtxsrc/rtxBitEncode.h"
#include "rtxsrc/rtxIntEncode.h"
#include "rtxsrc/rtx3GPP.h"
#include "rtxsrc/rtxDiagBitTrace.h"

EXTERN int NASEnc_TS24007L3_EPSBearerIdentity (OSCTXT* pctxt
   , TS24007L3_EPSBearerIdentity value)
{
   int ret = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "EPSBearerIdentity");

   /* Encode ENUMERATED value */
   switch (value) {
      case TS24007L3_EPSBearerIdentity_noIdent:
      case TS24007L3_EPSBearerIdentity_id5:
      case TS24007L3_EPSBearerIdentity_id6:
      case TS24007L3_EPSBearerIdentity_id7:
      case TS24007L3_EPSBearerIdentity_id8:
      case TS24007L3_EPSBearerIdentity_id9:
      case TS24007L3_EPSBearerIdentity_id10:
      case TS24007L3_EPSBearerIdentity_id11:
      case TS24007L3_EPSBearerIdentity_id12:
      case TS24007L3_EPSBearerIdentity_id13:
      case TS24007L3_EPSBearerIdentity_id14:
      case TS24007L3_EPSBearerIdentity_id15:
         break;

      default:
         rtxErrAddUIntParm (pctxt, value);
         return LOG_RTERR (pctxt, RTERR_INVENUM);
   }

   RTDIAG_NEWBITFIELD (pctxt, "ENUMERATED");

   ret = rtxEncBits (pctxt, value, 4);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);

   RTXCTXTPOPTYPENAME (pctxt);

   return (ret);
}

EXTERN int NASEnc_TS24007L3_ProtoDiscr (OSCTXT* pctxt
   , TS24007L3_ProtoDiscr value)
{
   int ret = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "ProtoDiscr");

   /* Encode ENUMERATED value */
   if (value >= 12) {
      rtxErrAddUIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }

   RTDIAG_NEWBITFIELD (pctxt, "ENUMERATED");

   ret = rtxEncBits (pctxt, value, 4);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);

   RTXCTXTPOPTYPENAME (pctxt);

   return (ret);
}

EXTERN int NASEnc_TS24007L3_SecHdrType (OSCTXT* pctxt
   , TS24007L3_SecHdrType value)
{
   int ret = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "SecHdrType");

   /* Encode ENUMERATED value */
   switch (value) {
      case TS24007L3_SecHdrType_noSec:
      case TS24007L3_SecHdrType_integProt:
      case TS24007L3_SecHdrType_integProtAndCipher:
      case TS24007L3_SecHdrType_integProtAndSecCtxt:
      case TS24007L3_SecHdrType_integProtAndCipherAndSecCtxt:
      case TS24007L3_SecHdrType_secHdrForSvcReq:
         break;

      default:
         rtxErrAddUIntParm (pctxt, value);
         return LOG_RTERR (pctxt, RTERR_INVENUM);
   }

   RTDIAG_NEWBITFIELD (pctxt, "ENUMERATED");

   ret = rtxEncBits (pctxt, value, 4);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);

   RTXCTXTPOPTYPENAME (pctxt);

   return (ret);
}

/* begin custom source file NASEnc_TS24007L3_L3HdrOptions.c */

/* Custom implementation */

EXTERN int NASEnc_TS24007L3_L3HdrOptions (OSCTXT* pctxt
   , TS24007L3_L3HdrOptions* pvalue)
{
   int ret = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "L3HdrOptions");

   /* Encode choice data value */

   switch (pvalue->t)
   {
      /* skipInd */
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "skipInd");

         if (pvalue->u.skipInd <= 15) {
            RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

            ret = rtxEncBits (pctxt, pvalue->u.skipInd, 4);
            if (ret < 0) return LOG_RTERR (pctxt, ret);

            RTDIAG_SETBITFLDCOUNT (pctxt);
         }
         else {
            rtxErrAddElemNameParm (pctxt);
            rtxErrAddUIntParm (pctxt, pvalue->u.skipInd);
            return LOG_RTERR (pctxt, RTERR_CONSVIO);
         }

         RTXCTXTPOPELEMNAME (pctxt);
         break;

      /* transId */
      case 2: {
         OSUINT8 transId = OSRTMIN (pvalue->u.transId.value, 7);
         RTXCTXTPUSHELEMNAME (pctxt, "transId");

         /* encode flag */

         RTXCTXTPUSHELEMNAME (pctxt, "flag");
         RTDIAG_NEWBITFIELD (pctxt, "BOOLEAN");

         ret = rtxEncBit (pctxt, pvalue->u.transId.flag);
         if (ret < 0) return LOG_RTERR (pctxt, ret);

         RTDIAG_SETBITFLDCOUNT (pctxt);
         RTXCTXTPOPELEMNAME (pctxt);

         /* encode value */

         RTXCTXTPUSHELEMNAME (pctxt, "value");
         RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

         ret = rtxEncBits (pctxt, transId, 3);
         if (ret < 0) return LOG_RTERR (pctxt, ret);

         RTDIAG_SETBITFLDCOUNT (pctxt);
         RTXCTXTPOPELEMNAME (pctxt);

         RTXCTXTPOPELEMNAME (pctxt);
         break;
      }

      /* epsBearerIdent */
      case 3:
         RTXCTXTPUSHELEMNAME (pctxt, "epsBearerIdent");

         ret = NASEnc_TS24007L3_EPSBearerIdentity (pctxt, pvalue->
            u.epsBearerIdent);
         if (ret < 0) return LOG_RTERR (pctxt, ret);

         RTXCTXTPOPELEMNAME (pctxt);
         break;

      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXTPOPTYPENAME (pctxt);

   return (ret);
}

/* end custom source file NASEnc_TS24007L3_L3HdrOptions.c */

EXTERN int NASEnc_TS24007L3_Header (OSCTXT* pctxt, TS24007L3_Header* pvalue)
{
   int ret = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "Header");

   /* encode l3HdrOpts */

   RTXCTXTPUSHELEMNAME (pctxt, "l3HdrOpts");

   ret = NASEnc_TS24007L3_L3HdrOptions (pctxt, &pvalue->l3HdrOpts);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTXCTXTPOPELEMNAME (pctxt);

   /* encode protoDiscr */

   RTXCTXTPUSHELEMNAME (pctxt, "protoDiscr");

   ret = NASEnc_TS24007L3_ProtoDiscr (pctxt, pvalue->protoDiscr);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTXCTXTPOPELEMNAME (pctxt);

   /* encode msgType */

   RTXCTXTPUSHELEMNAME (pctxt, "msgType");
   RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

   ret = rtxEncUInt32 (pctxt, pvalue->msgType, 1);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);
   RTXCTXTPOPELEMNAME (pctxt);

   RTXCTXTPOPTYPENAME (pctxt);

   return (ret);
}

EXTERN int NASEnc_TS24007L3_MsgType_MM_CC_SS (OSCTXT* pctxt
   , TS24007L3_MsgType_MM_CC_SS* pvalue)
{
   int ret = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "MsgType-MM-CC-SS");

   /* encode sendSeqNum */

   RTXCTXTPUSHELEMNAME (pctxt, "sendSeqNum");
   if (!((pvalue->sendSeqNum <= OSUINTCONST(3)))) {
      rtxErrAddElemNameParm (pctxt);
      rtxErrAddIntParm (pctxt, (int)pvalue->sendSeqNum);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

   ret = rtxEncBits (pctxt, pvalue->sendSeqNum, 2);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode value */

   RTXCTXTPUSHELEMNAME (pctxt, "value");
   if (!((pvalue->value <= OSUINTCONST(63)))) {
      rtxErrAddElemNameParm (pctxt);
      rtxErrAddIntParm (pctxt, (int)pvalue->value);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

   ret = rtxEncBits (pctxt, pvalue->value, 6);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);
   RTXCTXTPOPELEMNAME (pctxt);

   RTXCTXTPOPTYPENAME (pctxt);

   return (ret);
}

EXTERN int NASEnc_TS24007L3_SecProtMsgHeader (OSCTXT* pctxt
   , TS24007L3_SecProtMsgHeader* pvalue)
{
   int ret = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "SecProtMsgHeader");

   /* encode secHdrType */

   RTXCTXTPUSHELEMNAME (pctxt, "secHdrType");

   ret = NASEnc_TS24007L3_SecHdrType (pctxt, pvalue->secHdrType);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTXCTXTPOPELEMNAME (pctxt);

   /* encode protoDiscr */

   RTXCTXTPUSHELEMNAME (pctxt, "protoDiscr");
   if (!((pvalue->protoDiscr <= OSUINTCONST(15)))) {
      rtxErrAddElemNameParm (pctxt);
      rtxErrAddIntParm (pctxt, (int)pvalue->protoDiscr);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

   ret = rtxEncBits (pctxt, pvalue->protoDiscr, 4);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode msgAuthCode */

   RTXCTXTPUSHELEMNAME (pctxt, "msgAuthCode");
   RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

   ret = rtxEncUInt32 (pctxt, pvalue->msgAuthCode, 4);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode seqNumber */

   RTXCTXTPUSHELEMNAME (pctxt, "seqNumber");
   RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

   ret = rtxEncUInt32 (pctxt, pvalue->seqNumber, 1);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);
   RTXCTXTPOPELEMNAME (pctxt);

   RTXCTXTPOPTYPENAME (pctxt);

   return (ret);
}

