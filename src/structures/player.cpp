Player::Player(){
	this.id = -1;	// avoid debugging problems
	this.weight = -1;
}

Player::Player(int id, int weight) : 
	id(id), weight(weight) {}

