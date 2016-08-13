/*
 * Copyright (c) 2013 Objective Systems, Inc.
 *
 * This software is furnished under a license and may be used and copied
 * only in accordance with the terms of such license and with the
 * inclusion of the above copyright notice. This software or any other
 * copies thereof may not be provided or otherwise made available to any
 * other person. No title to and ownership of the software is hereby
 * transferred.
 *
 * The information in this software is subject to change without notice
 * and should not be construed as a commitment by Objective Systems, Inc.
 *
 * PROPRIETARY NOTICE
 *
 * This software is an unpublished work subject to a confidentiality agreement
 * and is protected by copyright and trade secret law.  Unauthorized copying,
 * redistribution or other use of this work is prohibited.
 *
 * The above notice of copyright on this source code product does not indicate
 * any actual or intended publication of such source code.
 *
 *****************************************************************************/
/**
 * @file rtoersrc/asn1oer.h
 * ASN.1 runtime constants, data structure definitions, and functions to
 * support the Octet Encoding Rules (OER) as defined in the National
 * Transportation Communications for ITS Protocol (NTCIP) 1102
 * standard.
 */
#ifndef _OSRTOER_H_
#define _OSRTOER_H_

#include "rtsrc/asn1type.h"
#include "rtsrc/asn1CharSet.h"
#include "rtxsrc/rtxBuffer.h"

/** @defgroup oerruntime OER Runtime Library Functions.
 * @{
 * The ASN.1 Octet Encoding Rules (OER) runtime library contains the
 * low-level constants, types, and functions that are assembled by the
 * compiler to encode/decode more complex structures.
 * The OER low-level C encode/decode functions are identified by their
 * prefixes: oerEnc for encode, oerDec for decode, and oerUtil for
 * utility functions.
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

#ifdef __SYMBIAN32__       /* For Symbian */
#define EXTOERCLASS

#ifdef BUILDASN1BERDLL
#define EXTERNOER      EXPORT_C
#define EXTOERMETHOD   EXPORT_C
#elif defined(USEASN1BERDLL)
#define EXTERNOER      IMPORT_C
#define EXTOERMETHOD   IMPORT_C
#else
#define EXTERNOER
#define EXTOERMETHOD
#endif /* BUILDASN1BERDLL */

#else                      /* Other O/S's */
#define EXTOERMETHOD

#ifdef BUILDASN1BERDLL
#define EXTERNOER      __declspec(dllexport)
#define EXTOERCLASS    __declspec(dllexport)
#elif defined (USEASN1BERDLL)
#define EXTERNOER      __declspec(dllimport)
#define EXTOERCLASS    __declspec(dllimport)
#else
#define EXTERNOER
#define EXTOERCLASS
#endif /* BUILDASN1BERDLL */

#endif

/* decode functions */
/** @defgroup oerdecruntime OER C Decode Functions.
 * @{
 *
 * OER C decode functions handle the decoding of the primitive ASN.1 data
 * types and ASN.1 length and tag fields within a message. Calls to these
 * functions are assembled in the C source code generated by the ASN1C compiler
 * to decode complex ASN.1 structures. These functions are also directly
 * callable from within a user's application program if the need to decode a
 * primitive data item exists.
 */
/**
 * This function decodes an OER bit string. This assumes a variable
 * length string. Fixed-sized strings (i.e SIZE(N)) are encoded with no
 * length or unused bit descriptors.  This is handled by the compiler.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to static byte array into which data is to be
 *                      read.  The buffer must be large enough to hold the
 *                      decoded value.
 * @param bufsiz      Size of the static byte array into which data is to
 *                      be read.
 * @param pnbits      Pointer to a variable to receive the decoded number
 *                      of bits.
 * @return            Completion status of operation:
 *                      - 0 (0) = success,
 *                      - negative return value is error.
 */
EXTERNOER int oerDecBitStr
(OSCTXT* pctxt, OSOCTET* pvalue, size_t bufsiz, OSUINT32* pnbits);

/**
 * This function decodes an OER bit string into a dynamic memory buffer.
 * Memory for the buffer is allocated using the rtxMemAlloc function and
 * should be subsequently freed using the rtxMemFree or rtxMemFreePtr
 * functions.  This assumes a variable length string. Fixed-sized strings
 * (i.e SIZE(N)) are encoded with no length or unused bit descriptors.
 * This is handled by the compiler.
 *
 * @param pctxt       Pointer to context block structure.
 * @param ppvalue     Pointer to receive pointer to allocated byte buffer.
 * @param pnbits      Pointer to a variable to receive the decoded number
 *                      of bits.
 * @return            Completion status of operation:
 *                      - 0 (0) = success,
 *                      - negative return value is error.
 */
EXTERNOER int oerDecDynBitStr
(OSCTXT *pctxt, OSOCTET** ppvalue, OSUINT32* pnbits);

/**
 * This function decodes an OER character string into a dynamic memory buffer.
 * Memory for the buffer is allocated using the rtxMemAlloc function and
 * should be subsequently freed using the rtxMemFree or rtxMemFreePtr
 * functions.
 *
 * @param pctxt       Pointer to context block structure.
 * @param ppvalue     Pointer to receive pointer to null-terminated char string.
 * @return            Completion status of operation:
 *                      - 0 (0) = success,
 *                      - negative return value is error.
 */
EXTERNOER int oerDecDynCharStr (OSCTXT *pctxt, char** ppvalue);

/**
 * This function decodes an OER octet string into a dynamic memory buffer.
 * Memory for the buffer is allocated using the rtxMemAlloc function and
 * should be subsequently freed using the rtxMemFree or rtxMemFreePtr
 * functions.
 *
 * @param pctxt       Pointer to context block structure.
 * @param ppvalue     Pointer to receive pointer to allocated byte buffer.
 * @param pnocts      Pointer to a variable to receive the decoded number
 *                      of octets (bytes).
 * @param len         Length of string to decoded.  If zero, it is assumed
 *                      the string is variable length and the length is
 *                      decoded within the funtion.
 * @return            Completion status of operation:
 *                      - 0 (0) = success,
 *                      - negative return value is error.
 */
EXTERNOER int oerDecDynOctStr
(OSCTXT *pctxt, OSOCTET** ppvalue, OSUINT32* pnocts, size_t len);

/**
 * This macro decodes an OER 8-bit signed integer at the current
 * message buffer/stream location and advances the pointer to the next field.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to decoded 16-bit integer value.
 * @return             Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
#define oerDecInt8(pctxt,pvalue) rtxReadBytes(pctxt,pvalue,1)

/**
 * This function decodes an OER 16-bit signed integer at the current
 * message buffer/stream location and advances the pointer to the next field.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to decoded 16-bit integer value.
 * @return             Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerDecInt16 (OSCTXT* pctxt, OSINT16* pvalue);

/**
 * This function decodes an OER 32-bit signed integer at the current
 * message buffer/stream location and advances the pointer to the next field.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to decoded 32-bit integer value.
 * @return             Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerDecInt32 (OSCTXT* pctxt, OSINT32* pvalue);

#if !defined(_NO_INT64_SUPPORT)
/**
 * This function decodes an OER unrestricted signed integer at the current
 * message buffer/stream location and advances the pointer to the next field.
 * It is assumed that the value will fit in a 64-bit integer variable.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to decoded 64-bit integer value.
 * @return             Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerDecInt64 (OSCTXT* pctxt, OSINT64* pvalue);
#endif

/**
 * This function is used to decode an OER length determinant value.
 *
 * @param pctxt       Pointer to context block structure.
 * @param plength     Pointer to variable to receive decoded length.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerDecLen (OSCTXT* pctxt, size_t* plength);

/**
 * This function is used to decode an OER object identifier value.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to variable to receive decoded value.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerDecObjId (OSCTXT* pctxt, ASN1OBJID* pvalue);

/**
 * This function is used to decode a signed enumerated value.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to variable to receive decoded value.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerDecSignedEnum (OSCTXT* pctxt, OSINT32* pvalue);

/**
 * This function decodes an ASN.1 tag into a standard 32-bit unsigned integer
 * type. The bits used to represent the components of a tag are as follows:
 *
 * Bit Fields:
 *   - 31-30 Class (00 = UNIV, 01 = APPL, 10 = CTXT, 11 = PRIV)
 *   - 29 Form (not used for OER)
 *   - 28-0 ID code value
 *
 * @param pctxt       Pointer to context block structure.
 * @param ptag        Pointer to variable to receive decoded tag info.
 * @return            Completion status of operation: 0 (0) = success,
 *                       negative return value is error.
 */
EXTERNOER int oerDecTag (OSCTXT* pctxt, ASN1TAG* ptag);

/**
 * This macro decodes an OER 8-bit unsigned integer at the current
 * message buffer/stream location and advances the pointer to the next field.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to decoded 16-bit integer value.
 * @return             Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
#define oerDecUInt8(pctxt,pvalue) rtxReadBytes(pctxt,pvalue,1)

/**
 * This function decodes an OER 16-bit unsigned integer at the current
 * message buffer/stream location and advances the pointer to the next field.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to decoded 16-bit integer value.
 * @return             Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerDecUInt16 (OSCTXT* pctxt, OSUINT16* pvalue);

/**
 * This function decodes an OER 32-bit unsigned integer at the current
 * message buffer/stream location and advances the pointer to the next field.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to decoded 32-bit integer value.
 * @return             Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerDecUInt32 (OSCTXT* pctxt, OSUINT32* pvalue);

#if !defined(_NO_INT64_SUPPORT)
/**
 * This function decodes an OER unrestricted unsigned integer at the current
 * message buffer/stream location and advances the pointer to the next field.
 * It is assumed that the value will fit in a 64-bit integer variable.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to decoded 64-bit integer value.
 * @return             Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerDecUInt64 (OSCTXT* pctxt, OSUINT64* pvalue);
#endif

/**
 * This function decodes an OER unrestricted signed integer at the current
 * message buffer/stream location and advances the pointer to the next field.
 * It is assumed that the value will fit in a 32-bit integer variable.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to decoded 32-bit integer value.
 * @return             Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerDecUnrestInt32 (OSCTXT* pctxt, OSINT32* pvalue);

/**
 * This function decodes an OER unrestricted unsigned integer at the current
 * message buffer/stream location and advances the pointer to the next field.
 * It is assumed that the value will fit in a 32-bit integer variable.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to decoded 32-bit integer value.
 * @return             Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerDecUnrestUInt32 (OSCTXT* pctxt, OSUINT32* pvalue);

/**
 * This function is used to decode an unsigned enumerated value.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to variable to receive decoded value.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerDecUnsignedEnum (OSCTXT* pctxt, OSUINT32* pvalue);

/** @} oerdecruntime */

/* encode functions */
/** @defgroup oerencruntime OER C Encode Functions.
 * @{
 *
 * OER C encode functions handle the OER encoding of the primitive ASN.1
 * data types and ASN.1 length and tag fields within a message. Calls to these
 * functions are assembled in the C source code generated by the ASN1C complier
 * to accomplish the encoding of complex ASN.1 structures. These functions are
 * also directly callable from within a user's application program if the need
 * to accomplish a low level encoding function exists.
 */
/**
 * This function encodes an OER bit string. This assumes a variable
 * length string. Fixed-sized strings (i.e SIZE(N)) are encoded with no
 * length or unused bit descriptors.  This is handled by the compiler.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to binary data to encode.
 * @param numbits     Number of bits in the bit string.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerEncBitStr
(OSCTXT* pctxt, const OSOCTET* pvalue, size_t numbits);

/**
 * This function encodes a known extesnion element in a SEQUENCE or
 * similar construct.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pbuffer     Pointer to run-time buffer containing encoded element.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
*/
EXTERNOER int oerEncExtElem (OSCTXT* pctxt, OSRTBuffer* pbuffer);

/**
 * This function encodes an OER fixed-size integer (1, 2, or 4 bytes)
 * and writes the encoded value to the output buffer/stream.
 *
 * @param pctxt       Pointer to context block structure.
 * @param value       Integer value to be encoded.
 * @param size        Size of the encoded field (1, 2, or 4 bytes).
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerEncInt32 (OSCTXT* pctxt, OSINT32 value, size_t size);

#if !defined(_NO_INT64_SUPPORT)
/**
 * This function encodes an OER unrestricted signed integer value
 * and writes the encoded value to the output buffer/stream.
 *
 * @param pctxt       Pointer to context block structure.
 * @param value       Integer value to be encoded.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerEncInt64 (OSCTXT* pctxt, OSINT64 value);
#endif

/**
 * This function is used to encode an OER length determinant value.
 *
 * @param pctxt       Pointer to context block structure.
 * @param length      The length to encode.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerEncLen (OSCTXT* pctxt, size_t length);

/**
 * This function is used to encode an OER object identifier value.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to variable containing value to encode.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerEncObjId (OSCTXT* pctxt, const ASN1OBJID* pvalue);

/**
 * This function will encode an ASN.1 open type extension. An open type
 * extension field is the data that potentially resides after the ... marker in
 * a version-1 message. The open type structure contains a complete encoded bit
 * set including option element bits or choice index, length, and data.
 * Typically, this data is populated when a version-1 system decodes a
 * version-2 message. The extension fields are retained and can then be
 * re-encoded if a new message is to be sent out (for example, in a store and
 * forward system).
 *
 * @param pctxt       Pointer to context block structure.
 * @param pElemList   A pointer to the open type to be encoded.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerEncOpenExt (OSCTXT* pctxt, OSRTDList* pElemList);

/**
 * This function is used to encode a signed OER enumerated value.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to variable containing value to encode.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerEncSignedEnum (OSCTXT* pctxt, OSINT32 value);

/**
 * This function encodes an ASN.1 tag specified using a standard 32-bit
 * unsigned integer type. The bits used to represent the components of a
 * tag are as follows:
 *
 * Bit Fields:
 *   - 31-30 Class (00 = UNIV, 01 = APPL, 10 = CTXT, 11 = PRIV)
 *   - 29 Form (not used for OER)
 *   - 28-0 ID code value
 *
 * @param pctxt       Pointer to context block structure.
 * @param tag         Tag value to be encoded.
 * @return            Completion status of operation: 0 (0) = success,
 *                       negative return value is error.
 */
EXTERNOER int oerEncTag (OSCTXT* pctxt, ASN1TAG tag);

/**
 * This function encodes an OER unsigned fixed-size integer (1, 2, or 4 bytes)
 * and writes the encoded value to the output buffer/stream.
 *
 * @param pctxt       Pointer to context block structure.
 * @param value       Integer value to be encoded.
 * @param size        Size of the encoded field (1, 2, or 4 bytes).
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerEncUInt32 (OSCTXT* pctxt, OSUINT32 value, size_t size);

#if !defined(_NO_INT64_SUPPORT)
/**
 * This function encodes an OER unsigned unrestricted signed integer value
 * and writes the encoded value to the output buffer/stream.
 *
 * @param pctxt       Pointer to context block structure.
 * @param value       Integer value to be encoded.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerEncUInt64 (OSCTXT* pctxt, OSUINT64 value);
#endif

/**
 * This function encodes an OER unrestricted signed integer value
 * and writes the encoded value to the output buffer/stream.
 *
 * @param pctxt       Pointer to context block structure.
 * @param value       Integer value to be encoded.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerEncUnrestInt32 (OSCTXT* pctxt, OSINT32 value);

/**
 * This function encodes an OER unrestricted unsigned integer value
 * and writes the encoded value to the output buffer/stream.
 *
 * @param pctxt       Pointer to context block structure.
 * @param value       Integer value to be encoded.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerEncUnrestUInt32 (OSCTXT* pctxt, OSUINT32 value);

/**
 * This function is used to encode an unsigned OER enumerated value.
 *
 * @param pctxt       Pointer to context block structure.
 * @param pvalue      Pointer to variable containing value to encode.
 * @return            Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNOER int oerEncUnsignedEnum (OSCTXT* pctxt, OSUINT32 value);

/** @} oerencruntime */

/* Internal functions */
int oerEncIdent (OSCTXT *pctxt, OSUINT32 ident);

#ifdef __cplusplus
}
#endif

/** @} oerruntime */

#endif /* _OSRTOER_H_ */
