/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:31:09 by amineau           #+#    #+#             */
/*   Updated: 2022/04/16 00:00:55 by amineau          ###   ########.fr       */
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

const std::string	usage()
{
	const std::string text =
		"./chessmaster\n"
		"\t-i --interface <string>\t\tInterface to use. Choices are `ncurses` and `cli`. Default `" + settings::defaultInterface + "`\n"
		"\t-f --fen <string>\t\tForsyth-Edwards Notation. Default `" + settings::defaultFenStart + "`\n"
		"\t-h --help\t\t\tPrint this help";
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

const struct user_options parse_args(int argc, char* argv[])
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
	int i = 1;
	short	menuResponse;
	short	loadResponse;
	std::vector<fs::path>	paths;
	std::vector<std::tuple<int, std::string, const char *>> backups;

	menuResponse = ui->displayMenu();
	switch (menuResponse) {
	case NEWGAME:
		ui->start(fen);
		break;

	case LOADGAME:
		if (!fs::exists(settings::backupPath))
		{
			std::cout << "No Game to load" << std::endl;
			fs::create_directory(settings::backupPath);
		}
		for (auto const& dir_entry : std::filesystem::directory_iterator{settings::backupPath}) 
		{
			fs::path file = dir_entry.path();
			if (!file.extension().compare(".fen"))
			{
				backups.push_back(std::make_tuple(i, file.stem(), time_to_str(fs::last_write_time(file))));
				paths.push_back(file);
			}
			i++;
		}
		loadResponse = ui->chooseBackup(backups);
		fen = readFile(paths.at(loadResponse - 1));
		ui->start(fen);
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
