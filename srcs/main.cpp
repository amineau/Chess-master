/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:31:09 by amineau           #+#    #+#             */
/*   Updated: 2021/08/01 17:37:30 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game/Chess.hpp"
#include "UserInterfaces/CLI.hpp"
#include "UserInterfaces/Ncurses.hpp"
#include "config.hpp"

int main(int argc, char* argv[])
{
	int			   c;
	short		   menuResponse;
	std::string	   interface = settings::defaultInterface;
	std::string	   fen = settings::defaultFenStart;
	UserInterface* ui;

	setlocale(LC_ALL, "");

	while (1) {
		static struct option long_options[] = {
			{ "interface", required_argument, NULL, 'i' },
			{ "fen", required_argument, NULL, 'f' },
			{ 0, 0, 0, 0 }
		};
		/* getopt_long stores the option index here. */
		int option_index = 0;

		c = getopt_long(argc, argv, "i:f:", long_options, &option_index);

		/* Detect the end of the options. */
		if (c == -1)
			break;

		switch (c) {
		case 0:
			/* If this option set a flag, do nothing else now. */
			if (long_options[option_index].flag != 0)
				break;
			printf("option %s", long_options[option_index].name);
			if (optarg)
				printf(" with arg %s", optarg);
			printf("\n");
			break;

		case 'i':
			printf("option -i with value `%s'\n", optarg);
			interface = optarg;
			break;

		case 'f':
			printf("option -f with value `%s'\n", optarg);
			fen = optarg;
			break;

		case '?':
			if (optopt == 'i' || optopt == 'f')
				fprintf(stderr, "Option -%c requires an argument.\n", optopt);
			else if (isprint(optopt))
				fprintf(stderr, "Unknown option `-%c'.\n", optopt);
			else
				fprintf(stderr,
					"Unknown option character `\\x%x'.\n",
					optopt);
			return EXIT_FAILURE;

		default:
			abort();
		}
	}

	/* Print any remaining command line arguments (not options). */
	if (optind != argc)
		return EXIT_FAILURE;

	if (interface.compare("cli") == 0)
		ui = new CLI();
	else if (interface.compare("ncurses") == 0)
		ui = new Ncurses();
	else
		return EXIT_FAILURE;

	menuResponse = ui->displayMenu();
	std::cout << menuResponse << std::endl;
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
	return EXIT_SUCCESS;
}
