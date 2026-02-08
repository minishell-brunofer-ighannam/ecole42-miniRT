/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:35:49 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/08 12:53:32 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
#define DEBUG_H

#include <pthread.h>
#include <stdio.h>



#define LOCK(m) \
  do { \
    pthread_mutex_lock(m); \
  } while (0)

#define UNLOCK(m) \
  do { \
    pthread_mutex_unlock(m); \
  } while (0)

#endif
