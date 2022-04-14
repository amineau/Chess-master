/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:31:09 by amineau           #+#    #+#             */
/*   Updated: 2022/04/14 23:40:21 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game/Chess.hpp"
#include "UserInterfaces/CLI.hpp"
#include "UserInterfaces/Ncurses.hpp"
#include "config.hpp"

struct user_options {
	std::string	   interface = settings::defaultInterface;
	std::string	   fen = settings::defaultFenStart;
};

const char *	usage()
{
	const char * text =
		"./chessmaster\n"
		"\t-i --interface <ncurses|cli>\tinterface to use. Default 'cli'\n"
		"\t-f --fen <string>\t\tfen. Default 'rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1'\n"
		"\t-h --help\t\t\tprint this help";
	return text;
}

void raise_on_no_command_line(int argc)
{
	if (optind != argc)
	{
		std::cerr << "Command not recognized" << std::endl;
		exit(EXIT_FAILURE);
	}
}

bool	is_end_options(int c)
{
	return c == -1;
}

struct user_options parse_args(int argc, char* argv[])
{
	struct user_options	user_options;
	static struct option long_options[] = {
		{ "interface", required_argument, NULL, 'i' },
		{ "fen", required_argument, NULL, 'f' },
		{ "help", no_argument, NULL, 'h' },
		{ 0, 0, 0, 0 }
	};
	int	c;
	int option_index;

	while (1) {
		/* getopt_long stores the option index here. */
		option_index = 0;
		c = getopt_long(argc, argv, "i:f:h", long_options, &option_index);

		if (is_end_options(c))
			break;

		switch (c) {
		case 0:
			break;
		case 'i':
			user_options.interface = optarg;
			break;
		case 'f':
			user_options.fen = optarg;
			break;
		case 'h':
			std::cout << usage() << std::endl;
			exit(EXIT_SUCCESS);
		case '?':
			if (optopt == 'i' || optopt == 'f')
				fprintf(stderr, "Option -%c requires an argument.\n", optopt);
			else if (isprint(optopt))
				fprintf(stderr, "Unknown option `-%c'.\n", optopt);
			else
				fprintf(stderr,
					"Unknown option character `\\x%x'.\n",
					optopt);
			exit(EXIT_FAILURE);
		default:
			abort();
		}
	}
	raise_on_no_command_line(argc);
	return user_options;

}

UserInterface*	get_user_interface(std::string interface)
{
	if (interface.compare("cli") == 0)
		return new CLI();
	else if (interface.compare("ncurses") == 0)
		return new Ncurses();
	std::cerr << "'" << interface << "' is not a valid ui option" << std::endl;
	std::cerr << usage() << std::endl;
	exit(EXIT_FAILURE);
}

void run_user_interface(UserInterface* ui, std::string fen)
{
	short		   		menuResponse;

	menuResponse = ui->displayMenu();
	switch (menuResponse) {
	case NEWGAME:
		ui->start(fen);
		break;

	case LOADGAME:
		std::cout << "Not Implemented" << std::endl;
		break;
	case QUIT:
	default:
		break;
	}
	delete ui;

}

int main(int argc, char* argv[])
{
	struct user_options user_options;
	UserInterface* 		ui;

	setlocale(LC_ALL, "");

	user_options = parse_args(argc, argv);
	ui = get_user_interface(user_options.interface);
	run_user_interface(ui, user_options.fen);
	return EXIT_SUCCESS;
}
