/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.6.2-pre4, Date: 04-Apr-2013.
 */
#include "TS24011IES.h"
#include "rtxsrc/rtxCommon.h"
#include "rtxsrc/rtxBitEncode.h"
#include "rtxsrc/rtxIntEncode.h"
#include "rtxsrc/rtx3GPP.h"
#include "rtxsrc/rtxDiagBitTrace.h"

EXTERN int NASEnc_TS24011IE_CPUserData (OSCTXT* pctxt
   , TS24011IE_CPUserData* pvalue)
{
   int ret = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CPUserData");

   RTDIAG_NEWBITFIELD (pctxt, "OCTET STRING");

   if (!(pvalue->numocts <= 249)) {
      rtxErrAddElemNameParm (pctxt);
      rtxErrAddIntParm (pctxt, (int)pvalue->numocts);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   ret = rtxEncUInt32 (pctxt, pvalue->numocts, 1);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   ret = rtxWriteBytes (pctxt, pvalue->data, pvalue->numocts);

   RTDIAG_SETBITFLDCOUNT (pctxt);

   RTXCTXTPOPTYPENAME (pctxt);

   return (ret);
}

EXTERN int NASEnc_TS24011IE_RPAddress (OSCTXT* pctxt
   , TS24011IE_RPAddress* pvalue)
{
   OSSIZE startIndex;
   int ret = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "RPAddress");

   /* encode length */

   RTXCTXTPUSHELEMNAME (pctxt, "length");
   RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

   ret = rtxEncUInt32 (pctxt, 0, 1);
   if (ret < 0) return LOG_RTERR (pctxt, ret);
   startIndex = pctxt->buffer.byteIndex;

   RTDIAG_SETBITFLDCOUNT (pctxt);

   RTXCTXTPOPELEMNAME (pctxt);

   /* encode ext */

   RTXCTXTPUSHELEMNAME (pctxt, "ext");
   RTDIAG_NEWBITFIELD (pctxt, "BOOLEAN");

   ret = rtxEncBit (pctxt, pvalue->ext);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode typeOfNumber */

   RTXCTXTPUSHELEMNAME (pctxt, "typeOfNumber");
   if (!((pvalue->typeOfNumber <= OSUINTCONST(7)))) {
      rtxErrAddElemNameParm (pctxt);
      rtxErrAddIntParm (pctxt, (int)pvalue->typeOfNumber);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

   ret = rtxEncBits (pctxt, pvalue->typeOfNumber, 3);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode numberingPlanID */

   RTXCTXTPUSHELEMNAME (pctxt, "numberingPlanID");
   if (!((pvalue->numberingPlanID <= OSUINTCONST(15)))) {
      rtxErrAddElemNameParm (pctxt);
      rtxErrAddIntParm (pctxt, (int)pvalue->numberingPlanID);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

   ret = rtxEncBits (pctxt, pvalue->numberingPlanID, 4);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode number */

   RTXCTXTPUSHELEMNAME (pctxt, "number");

   ret = NASEnc_TS24008IE_TBCDString (pctxt, pvalue->number);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTXCTXTPOPELEMNAME (pctxt);

   rtxByteAlign (pctxt);
   pvalue->length = pctxt->buffer.byteIndex - startIndex;
   pctxt->buffer.data[startIndex-1] = (OSUINT8) pvalue->length;
   if (!((pvalue->length <= OSUINTCONST(11)))) {
      rtxErrAddElemNameParm (pctxt);
      rtxErrAddIntParm (pctxt, (int)pvalue->length);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   RTXCTXTPOPTYPENAME (pctxt);

   return (ret);
}

EXTERN int NASEnc_TS24011IE_RPOriginatorAddress (OSCTXT* pctxt
   , TS24011IE_RPOriginatorAddress* pvalue)
{
   int ret = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "RPOriginatorAddress");

   ret = NASEnc_TS24011IE_RPAddress (pctxt, pvalue);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTXCTXTPOPTYPENAME (pctxt);

   return (ret);
}

EXTERN int NASEnc_TS24011IE_RPDestinationAddress (OSCTXT* pctxt
   , TS24011IE_RPDestinationAddress* pvalue)
{
   int ret = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "RPDestinationAddress");

   ret = NASEnc_TS24011IE_RPAddress (pctxt, pvalue);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTXCTXTPOPTYPENAME (pctxt);

   return (ret);
}

EXTERN int NASEnc_TS24011IE_RPUserData (OSCTXT* pctxt
   , TS24011IE_RPUserData* pvalue)
{
   int ret = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "RPUserData");

   RTDIAG_NEWBITFIELD (pctxt, "OCTET STRING");

   if (!(pvalue->numocts <= 233)) {
      rtxErrAddElemNameParm (pctxt);
      rtxErrAddIntParm (pctxt, (int)pvalue->numocts);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   ret = rtxEncUInt32 (pctxt, pvalue->numocts, 1);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   ret = rtxWriteBytes (pctxt, pvalue->data, pvalue->numocts);

   RTDIAG_SETBITFLDCOUNT (pctxt);

   RTXCTXTPOPTYPENAME (pctxt);

   return (ret);
}

EXTERN int NASEnc_TS24011IE_CPCauseValue (OSCTXT* pctxt
   , TS24011IE_CPCauseValue* pvalue)
{
   int ret = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CPCauseValue");

   /* encode ext */

   RTXCTXTPUSHELEMNAME (pctxt, "ext");
   RTDIAG_NEWBITFIELD (pctxt, "BOOLEAN");

   ret = rtxEncBit (pctxt, pvalue->ext);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode value */

   RTXCTXTPUSHELEMNAME (pctxt, "value");
   if (!((pvalue->value <= OSUINTCONST(127)))) {
      rtxErrAddElemNameParm (pctxt);
      rtxErrAddIntParm (pctxt, (int)pvalue->value);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

   ret = rtxEncBits (pctxt, pvalue->value, 7);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);
   RTXCTXTPOPELEMNAME (pctxt);

   RTXCTXTPOPTYPENAME (pctxt);

   return (ret);
}

EXTERN int NASEnc_TS24011IE_RPCauseElem (OSCTXT* pctxt
   , TS24011IE_RPCauseElem* pvalue)
{
   OSSIZE startIndex;
   int ret = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "RPCauseElem");

   /* encode length */

   RTXCTXTPUSHELEMNAME (pctxt, "length");
   RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

   ret = rtxEncUInt32 (pctxt, 0, 1);
   if (ret < 0) return LOG_RTERR (pctxt, ret);
   startIndex = pctxt->buffer.byteIndex;

   RTDIAG_SETBITFLDCOUNT (pctxt);

   RTXCTXTPOPELEMNAME (pctxt);

   /* encode ext */

   RTXCTXTPUSHELEMNAME (pctxt, "ext");
   RTDIAG_NEWBITFIELD (pctxt, "BOOLEAN");

   ret = rtxEncBit (pctxt, pvalue->ext);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode causeValue */

   RTXCTXTPUSHELEMNAME (pctxt, "causeValue");
   if (!((pvalue->causeValue <= OSUINTCONST(127)))) {
      rtxErrAddElemNameParm (pctxt);
      rtxErrAddIntParm (pctxt, (int)pvalue->causeValue);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

   ret = rtxEncBits (pctxt, pvalue->causeValue, 7);
   if (ret < 0) return LOG_RTERR (pctxt, ret);

   RTDIAG_SETBITFLDCOUNT (pctxt);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode diagField */

   RTXCTXTPUSHELEMNAME (pctxt, "diagField");
   {
      OSUINT8 i;
      if (!(pvalue->diagField.n <= 1)) {
         rtxErrAddElemNameParm (pctxt);
         rtxErrAddIntParm (pctxt, (int)pvalue->diagField.n);
         return LOG_RTERR (pctxt, RTERR_CONSVIO);
      }

      for (i = 0; i < pvalue->diagField.n; i++) {
         RTXCTXTPUSHARRAYELEMNAME (pctxt, "elem", i);
         RTDIAG_NEWBITFIELD (pctxt, "INTEGER");

         ret = rtxEncUInt32 (pctxt, pvalue->diagField.elem[i], 1);
         if (ret < 0) return LOG_RTERR (pctxt, ret);

         RTDIAG_SETBITFLDCOUNT (pctxt);
         RTXCTXTPOPARRAYELEMNAME (pctxt);
      }
   }

   RTXCTXTPOPELEMNAME (pctxt);

   rtxByteAlign (pctxt);
   pvalue->length = pctxt->buffer.byteIndex - startIndex;
   pctxt->buffer.data[startIndex-1] = (OSUINT8) pvalue->length;
   if (!((pvalue->length >= OSUINTCONST(1) && pvalue->length <= OSUINTCONST(2)))) {
      rtxErrAddElemNameParm (pctxt);
      rtxErrAddIntParm (pctxt, (int)pvalue->length);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   RTXCTXTPOPTYPENAME (pctxt);

   return (ret);
}

