/*
 * Copyright (C) u-blox Cambourne Ltd
 * u-blox Cambourne Ltd, Cambourne, UK
 *
 * All rights reserved.
 *
 * This source file is the sole property of u-blox Cambourne Ltd.
 * Reproduction or utilisation of this source in whole or part is
 * forbidden without the written consent of u-blox Cambourne Ltd.
 */

#ifndef _CELLULAR_PORT_UART_H_
#define _CELLULAR_PORT_UART_H_

/** Porting layer for UART access functions.  These functions
 * are threadsafe.
 */

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS
 * -------------------------------------------------------------- */

#ifndef CELLULAR_PORT_UART_RX_BUFFER_SIZE
/** The size of ring buffer to use for receive.
 */
# define CELLULAR_PORT_UART_RX_BUFFER_SIZE 1024
#endif

#ifndef CELLULAR_PORT_UART_TX_BUFFER_SIZE
/** The size of ring buffer to use for transmit.
 * 0 means blocking.
 */
# define CELLULAR_PORT_UART_TX_BUFFER_SIZE 0
#endif

#ifndef CELLULAR_PORT_UART_EVENT_QUEUE_SIZE
/** The event queue size.
 */
# define CELLULAR_PORT_UART_EVENT_QUEUE_SIZE 20
#endif

/* ----------------------------------------------------------------
 * TYPES
 * -------------------------------------------------------------- */

/* ----------------------------------------------------------------
 * FUNCTIONS
 * -------------------------------------------------------------- */

/** Initialise a UART.  If the UART has already been initialised
 * this function just returns.
 *
 * @param pinTx           the transmit (output) pin.
 * @param pinRx           the receive (input) pin.
 * @param pinCts          the CTS (input) flow control pin, asserted
 *                        by the modem when it is ready to receive
 *                        data; use -1 for none.
 * @param pinRts          the RTS (output) flow control pin, asserted
 *                        when we are ready to receive data from the
 *                        modem; use -1 for none.
 * @param baudRate        the baud rate to use.
 * @param rtsThreshold    the buffer length at which pinRts is
 *                        de-asserted.  Ignored if pinRts is -1.
 * @param uart            the UART number to use.
 * @param pUartQueue      a place to put the UART event queue.
 * @return                0 on success, otherwise negative error code.
 */
int32_t cellularPortUartInit(int32_t pinTx, int32_t pinRx,
                             int32_t pinCts, int32_t pinRts,
                             int32_t baudRate,
                             size_t rtsThreshold,
                             int32_t uart,
                             CellularPortQueueHandle_t *pUartQueue);

/** Shutdown a UART.  Note that this should NOT be called if a UART
 * read or write might be in progress.
 *
 * @param uart the UART number to shut down.
 * @return     0 on success, otherwise negative error code.
 */
int32_t cellularPortUartDeinit(int32_t uart);

/** Read from the given UART interface.  Any characters
 * already available will be returned; no waiting around.
 *
 * @param uart      the UART number to use.
 * @param pBuffer   a pointer to a buffer in which to store
 *                  received bytes.
 * @param sizeBytes the size of buffer pointed to by pBuffer.
 * @return          the number of bytes received or negative
 *                  error code.
 */
int32_t cellularPortUartRead(int32_t uart, char *pBuffer,
                             size_t sizeBytes);

/** Write to the given UART interface.  The function will
 * block until all the data has been written.
 *
 * @param uart      the UART number to use.
 * @param pBuffer   a pointer to a buffer of data to send.
 * @param sizeBytes the number of bytes in pBuffer.
 * @return          the number of bytes sent or negative
 *                  error code.
 */
int32_t cellularPortUartWrite(int32_t uart,
                              const char *pBuffer,
                              size_t sizeBytes);

#endif // _CELLULAR_PORT_UART_H_

// End of file
