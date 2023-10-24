idf_component_register(SRCS CANopen.c CO_driver.c CO_Emergency.c CO_HBconsumer.c CO_LSSmaster.c CO_LSSslave.c CO_NMT_Heartbeat.c CO_PDO.c CO_SDO.c CO_SDOmaster.c CO_SYNC.c CO_TIME.c CO_trace.c crc16-ccitt.c
                                INCLUDE_DIRS "." "../../include" "../../main/"
                                REQUIRES
                            )