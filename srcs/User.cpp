
#include "irc.hpp"
#include "User.hpp"

std::string	User::_parseRealName(std::vector<std::string> args)
{
	std::string 	real_name;
	unsigned int	args_size;

	args_size = args.size();
	real_name = args.at(4).erase(0, 1);
	for (unsigned int i = 5; i < args_size; i++)
	{
		real_name += " ";
		real_name += args.at(i);
	}
	return (real_name);
}

bool User::userCommand(int socket, Client &client, std::vector<std::string> args)
{
	if (!client.getUserName().empty())
	{
		Server::sendAnswer(socket, client.getNick(), ERR_ALREADYREGISTERED, ":Already registered as " + client.getUserName());
		return (false);
	}
	client.setUserName(args.at(1));
	client.setHostName(args.at(2));
	client.setRealName(_parseRealName(args));
	return (true);
}