/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:09:32 by tpoho             #+#    #+#             */
/*   Updated: 2023/10/02 19:14:02 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ToolFunctions.hpp"
#include "../includes/Part.hpp"

void Part::partcmd(int socket, std::string full_command, t_server_mode	&_serverSettings)
{
	std::vector<std::string> command_parts;
	std::vector<std::string> temp_channels;
	ToolFunctions::_split_command_in_parts(full_command, command_parts);

	std::cout << "partcmd entered" << std::endl;

	switch(command_parts.size())
	{
		case 0:
			// Should not come to here
			break;

		case 1:
			// Should not come to here
			break;

		case 2:
			ToolFunctions::_parse_into_parts(command_parts, 1, temp_channels);
			for (std::vector<std::string>::size_type i = 0; i < temp_channels.size(); ++i)
			{
				for (std::vector<Channel>::size_type k = 0; k < _serverSettings.channels.size(); ++k)
				{
					if (temp_channels.at(i) == _serverSettings.channels.at(k).getChannelName())
					{
						if (_serverSettings.channels.at(k).isOnChannel(socket))
						{
							_serverSettings.channels.at(k).partFromChannel(socket);
							//Server::sendAnswer(socket, _findNickName(socket, _serverSettings.clients), 666, "Already on channel")
							break ;
						}else
						{
							// What to send if not in channel?
							//Server::sendAnswer(socket, _findNickName(socket, _serverSettings.clients), 666, "Parted channel")
							break;
						}
					}
				}	
			}
			break;

		default:
			ToolFunctions::_parse_into_parts(command_parts, 1, temp_channels);
			std::string rest_of_string = _return_last_part_of_string(2, full_command);
			for (std::vector<std::string>::size_type i = 0; i < temp_channels.size(); ++i)
			{
				for (std::vector<Channel>::size_type k = 0; k < _serverSettings.channels.size(); ++k)
				{
					if (temp_channels.at(i) == _serverSettings.channels.at(k).getChannelName())
					{
						if (_serverSettings.channels.at(k).isOnChannel(socket))
						{
							_serverSettings.channels.at(k).partFromChannel(socket);
							//Server::sendAnswer(socket, _findNickName(socket, _serverSettings.clients), 666, "rest_of_string")
							break ;
						}else
						{
							// What to send if not in channel?
							//Server::sendAnswer(socket, _findNickName(socket, _serverSettings.clients), 666, "rest_of_string")
							break;
						}
					}
				}	
			}
			break;
	}
}

std::string Part::_return_last_part_of_string(int begin, std::string full_command)
{
	std::string temp;
	std::string last_part;
	std::istringstream ss(full_command);

	for (int i = 0; i < begin; ++i)
	{
		ss >> temp;
	}

	if (!ss.fail())
	{
		ss >> std::ws; // Skip leading whitespace
		std::getline(ss, last_part);
		return (last_part);
    }else
		return ("Error: no message even there should be");
}