
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:16:14 by tpoho             #+#    #+#             */
/*   Updated: 2023/09/29 16:40:41 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <string>
# include <vector>

typedef struct s_channel_mode
{
	std::string					nameOfChannel;	// Name of channel
	std::vector<int>			channelMembers;	// Who are on channel
	int							i;				// Is invite only channel
	std::vector<int>			invitedClients;	// List of invitations, one time only remember to delete once used
	int							t;				// Restrict topic to only ops
	std::string					topic;			// Topic that is printed when you join channel
	std::string					k;				// channel key (password)
	std::vector<int>			o;				// Who has the ops
	int							l;				// Limit of how many users can join into a channel
	std::vector<std::string>	b;				// List of banned sockets
}	t_channel_mode;

class Channel
{
	public:

		Channel(const std::string nameOfChannel, int socketDescriptor);
		~Channel();
		Channel(const Channel &copy_constructor);
		Channel	&operator=(const Channel &copy_assignment);

		std::string	getChannelName() const;
		std::string	getTopic() const;
		void		setTopic(std::string input);
		int			isInviteOnly() const;
		int			isTopicMode() const;
		int			isClientInvited(int socket) const;
		void		addInvitation(int socket);
		void		removeInvitation(int socket);
		int			isOnChannel(int socket) const;
		void		addToChannel(int socket);
		void		partFromChannel(int socket);
		int			howManyMembersOnChannel() const;
		int			isThereKey() const;
		void		setKey(std::string new_key);
		int			doesKeyMatch(const std::string &key) const;
		void		printDebug() const;
		void		sendToAllChannelMembers(const std::string message);
		const std::vector<int>& returnChannelMembers() const;
		int 		hasOps(int socket) const;
		void		giveOps(int socket);
		void		removeOps(int socket);
		void		setInviteMode(int mode);
		void		setTopicMode(int mode);
		void		setUserLimit(int amount);


	private:

		Channel();


		t_channel_mode _channelSettings;
};

#endif
