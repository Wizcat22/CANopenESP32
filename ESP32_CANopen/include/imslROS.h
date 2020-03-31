/**
 * @file imslRos.h
 * @author Alexander Miller (alexander.miller@fh-dortmund.de)
 * @brief Rosserial
 * @version 0.1
 * @date 2019-09-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef IMSLROS_H_
#define IMSLROS_H_

#ifdef __cplusplus
extern "C"
{
#endif

  /**
   * @brief Initialize Rosserial
   * 
   */
  void rosserialSetup();

  /**
   * @brief Publish all topics with Rosserial
   * 
   */
  void rosserialPublish();

  void NodeHandleSpin();

#ifdef __cplusplus
}
#endif

#endif /* IMSLROS_H_ */