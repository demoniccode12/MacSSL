/* Standard mbedTLS config for Classic Mac OS 8.6 with x25519 support */
#ifndef MBEDTLS_CONFIG_H
#define MBEDTLS_CONFIG_H

/* Include compatibility headers first */
#include "mbedtls_compat.h"

/* System support */
#undef MBEDTLS_HAVE_ASM
#undef MBEDTLS_HAVE_TIME      /* Explicitly disable time functions */
#undef MBEDTLS_ENTROPY_PLATFORM
#undef MBEDTLS_FS_IO
#define MBEDTLS_NO_PLATFORM_ENTROPY
#define MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES
#undef MBEDTLS_TIMING_C
#undef MBEDTLS_HAVEGE_C

/* use the 'portable c' implemention of multi-precision arithmetic */
#define MBEDTLS_NO_UDBL_DIVISION

/* Disable threading - Classic Mac OS doesn't have POSIX threads */
#undef MBEDTLS_THREADING_C
#undef MBEDTLS_THREADING_PTHREAD

/* Disable features we don't need */
#undef MBEDTLS_ZLIB_SUPPORT
#undef MBEDTLS_PKCS11_C
#undef MBEDTLS_PKCS12_C
#undef MBEDTLS_CMAC_C
#undef MBEDTLS_NET_C  /* We'll implement our own using Open Transport */
#undef MBEDTLS_SSL_CACHE_C
#undef MBEDTLS_SSL_SESSION_TICKETS
#undef MBEDTLS_XTEA_C
#undef MBEDTLS_HAVE_INT64

/* Reduce memory requirements */
#define MBEDTLS_SSL_MAX_CONTENT_LEN 8192
#define MBEDTLS_MPI_MAX_SIZE 512

/* Core modules */
#define MBEDTLS_SSL_CLI_C
#define MBEDTLS_SSL_TLS_C
#define MBEDTLS_SSL_PROTO_TLS1
#define MBEDTLS_SSL_PROTO_TLS1_1
#define MBEDTLS_SSL_PROTO_TLS1_2
#define MBEDTLS_SSL_PROTO_SSL3
#define MBEDTLS_SSL_RENEGOTIATION

/* Server Name Indication */
#define MBEDTLS_SSL_SERVER_NAME_INDICATION

/* Debug support */
#define MBEDTLS_DEBUG_C
#define MBEDTLS_ERROR_C

/* Crypto algorithms - compatible with server */
#define MBEDTLS_AES_C
#define MBEDTLS_CIPHER_MODE_CBC
#define MBEDTLS_CIPHER_C
#define MBEDTLS_DHM_C
#define MBEDTLS_RSA_C
#define MBEDTLS_MD_C
#define MBEDTLS_MD5_C
#define MBEDTLS_SHA1_C
#define MBEDTLS_SHA256_C
#define MBEDTLS_X509_CRT_PARSE_C

/* Elliptic curves - IMPORTANT: add x25519 support */
#define MBEDTLS_SSL_ECP_RESTARTABLE
#define MBEDTLS_ECDH_C
#define MBEDTLS_ECDSA_C
#define MBEDTLS_ECP_C
#define MBEDTLS_ECP_DP_SECP256R1_ENABLED
#define MBEDTLS_ECP_DP_SECP384R1_ENABLED
#define MBEDTLS_ECP_DP_CURVE25519_ENABLED  /* This is critical */

/* Key exchange algorithms */
#define MBEDTLS_KEY_EXCHANGE_RSA_ENABLED
#define MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED
#define MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED
#define MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED

/* Modern cipher support */
#define MBEDTLS_GCM_C
#define MBEDTLS_CIPHER_MODE_GCM
#define MBEDTLS_CHACHA20_C
#define MBEDTLS_POLY1305_C
#define MBEDTLS_CHACHAPOLY_C

/* RSA is widely supported */
#define MBEDTLS_RSA_C
#define MBEDTLS_PKCS1_V15
#define MBEDTLS_BIGNUM_C
#define MBEDTLS_OID_C

/* Certificate handling */
#define MBEDTLS_X509_USE_C
#define MBEDTLS_X509_CRT_PARSE_C
#define MBEDTLS_ASN1_PARSE_C
#define MBEDTLS_ASN1_WRITE_C
#define MBEDTLS_PK_C
#define MBEDTLS_PK_PARSE_C
#define MBEDTLS_PEM_PARSE_C
#define MBEDTLS_BASE64_C

/* Random number generation */
#define MBEDTLS_CTR_DRBG_C
#define MBEDTLS_ENTROPY_C
#define MBEDTLS_ENTROPY_HARDWARE_ALT  /* We'll implement our own */

/* Allow fallback to simpler ciphers when needed */
#define MBEDTLS_SSL_FALLBACK_SCSV
//#define MBEDTLS_SSL_CBC_RECORD_SPLITTING

/* Critical: Don't disable signature algorithms extension */
#undef MBEDTLS_SSL_DISABLE_SIGNATURE_ALGORITHMS_EXTENSION

/* Platform customization */
#define MBEDTLS_PLATFORM_C
#define MBEDTLS_PLATFORM_MEMORY
#define MBEDTLS_MEMORY_BUFFER_ALLOC_C
#define MBEDTLS_SSL_OUT_CONTENT_LEN 8192
#define MBEDTLS_SSL_IN_CONTENT_LEN 8192
#define MBEDTLS_MEMORY_DEBUG

/* Use our custom printf */
#define MBEDTLS_PLATFORM_PRINTF_MACRO mac_printf
int mac_printf(const char *format, ...);

/* Error handling */
#define MBEDTLS_ERROR_C


/* Check this configuration */
#include "check_config.h"

#endif /* MBEDTLS_CONFIG_H */