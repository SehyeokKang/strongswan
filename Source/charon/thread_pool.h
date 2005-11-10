/**
 * @file thread_pool.h
 * 
 * @brief Thread pool with some threads processing the job_queue
 * 
 */

/*
 * Copyright (C) 2005 Jan Hutter, Martin Willi
 * Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_

#include <stdlib.h>

#include "types.h"

/**
 * @brief A thread_pool contains a pool of threads processing the job queue.
 * 
 * Current implementation uses as many threads as specified in constructor.
 * A more improved version would dynamically increase thread count if necessary...
 */
typedef struct thread_pool_s thread_pool_t;

struct thread_pool_s {
	/**
	 * @brief return currently instanciated threads
	 * 
	 * @param thread_pool	thread_pool_t object		
	 * @return				size of thread pool
	 */
	size_t (*get_pool_size) (thread_pool_t *thread_pool);
	/**
	 * @brief destroy pool
	 * 
	 * sends cancellation request to all threads and AWAITS their termination.
	 * 
	 * @param thread_pool	thread_pool_t object
	 * @return				
	 * 						- SUCCESS in any case
	 */
	status_t (*destroy) (thread_pool_t *thread_pool);
};

/**
 * @brief Create the thread pool using using pool_size of threads
 *  
 * @param pool_size			desired pool size
 * @return 					
 * 							- NULL if no threads could be created
 * 							- thread_pool if one ore more threads could be instanciated
 */
thread_pool_t *thread_pool_create(size_t pool_size);


#endif /*THREAD_POOL_H_*/
