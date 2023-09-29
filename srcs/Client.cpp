// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Client.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tpoho <marvin@42.fr>                       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/09/29 17:38:35 by tpoho             #+#    #+#             //
//   Updated: 2023/09/29 17:38:36 by tpoho            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Client.hpp"

Client::Client(): _socket(0), _nickName("*")
{

}

Client::~Client()
{

}

int	Client::getSocket() const
{
	return (_socket);
}

void	Client::setSocket(int socket)
{
	_socket = socket;
}

void	Client::setNick(std::string nickName)
{
	_nickName = nickName;
}

std::string	Client::getNick() const
{
	return (_nickName);
}
