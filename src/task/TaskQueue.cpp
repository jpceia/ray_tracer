/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TaskQueue.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:39:20 by jpceia            #+#    #+#             */
/*   Updated: 2022/03/11 16:03:23 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "task/TaskQueue.hpp"
#include "task/Task.hpp"
#include "task/LockGuard.hpp"
#include <pthread.h>

TaskQueue::TaskQueue() :
    _stopped(false)
{
}

TaskQueue::TaskQueue(TaskQueue const &rhs)
{
    (void)rhs;
}

TaskQueue::~TaskQueue()
{
}

TaskQueue& TaskQueue::operator=(TaskQueue const &rhs)
{
    (void)rhs;
    return *this;
}

void TaskQueue::push(Task *task)
{
    if (_stopped)
        return;
    if (task == NULL)
    {
        _stopped = true;
        _cond.broadcast();
        return;
    }
    else
    {
        LockGuard lock(_mutex);
        _queue.push(task);
    }
    _cond.signal();
}

Task* TaskQueue::pop()
{
    LockGuard lock(_mutex);

    while (_queue.empty() && !_stopped)
        _cond.wait(_mutex);
    if (_queue.empty())
        return NULL;
    Task *task = _queue.front();
    _queue.pop();
    return task;
}

bool TaskQueue::isStopped()
{
    return _stopped;
}