#include <cstdlib>
#include <iostream>

namespace RSP {
	enum Item {
		PAPER, ROCK, SCISSOR
	};

	class player {
		public:
			Item item;

		player();

		void invent();
		bool compare(player *player);
	};

	player::player() {}

	void player::invent () {
		this->item = static_cast<Item>(rand() % 3);
	}

	bool player::compare (player *player) {
		this->invent();
		player->invent();
		return
			this->item == PAPER && player->item == ROCK ||
			this->item == SCISSOR && player->item == PAPER;
	}
}

int main () {
	using namespace RSP;
	player *player1 = new player;
	player *player2 = new player;

	//10 rounds
	for (int i = 1; i <= 10; i++) {
		std::cout << player1->compare(player2) << '\n';
	}

	return 0;
}