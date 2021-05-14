/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:31:09 by amineau           #+#    #+#             */
/*   Updated: 2021/05/14 22:45:03 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Chess.hpp"
#include "UserInterfaceCLI.hpp"
#include "UserInterfaceNcurses.hpp"
#include "chessmaster.hpp"

int main(int argc, char* argv[])
{
	int			   c;
	short		   menuResponse;
	std::string	   interface = settings::defaultInterface;
	UserInterface* ui;

	setlocale(LC_ALL, "");

	while (1) {
		static struct option long_options[] = {
			{ "interface", required_argument, 0, 'i' },
			{ 0, 0, 0, 0 }
		};
		/* getopt_long stores the option index here. */
		int option_index = 0;

		c = getopt_long(argc, argv, "i:", long_options, &option_index);

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

		case '?':
			if (optopt == 'i')
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
		ui = new UserInterfaceCLI();
	else if (interface.compare("ncurses") == 0)
		ui = new UserInterfaceNcurses();
	else
		return EXIT_FAILURE;

	menuResponse = ui->displayMenu();
	std::cout << menuResponse << std::endl;
	switch (menuResponse) {
	case NEWGAME:
		ui->start();
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
