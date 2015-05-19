#!/usr/bin/python
import sys, random

MAX_SCORE_DIFFERENCE = 5

def get_random_weights(number_of_players, max_weight):
	return map(lambda _: random.randint(0, max_weight), range(number_of_players))

def get_random_weights_with_sum(players, total_weight):
	weights = get_random_weights(players, total_weight / players)
	total_current_weight = sum(weights)

	weight_per_player_left = (total_weight - total_current_weight)/players

	i = 0
	while total_current_weight != total_weight:
		if total_weight - total_current_weight > weight_per_player_left:	# total weight not reachable yet
			weights[i] += weight_per_player_left + 1
			total_current_weight += weight_per_player_left + 1
		else:
			weights[i] += total_weight - total_current_weight
			total_current_weight = total_weight

		i += 1


	return weights

def get_team_sizes(number_of_players):
	first_team_size = random.randint(1, number_of_players - 1)
	return first_team_size, number_of_players - first_team_size


N = int(sys.argv[1])

if len(sys.argv) == 3:	# if there is a second argument
	score_difference = 0
else:
	score_difference = random.randint(1, MAX_SCORE_DIFFERENCE)

team1_size, team2_size = get_team_sizes(N)

first_team_weigths = get_random_weights_with_sum(team1_size, N * 50)
second_team_weights = get_random_weights_with_sum(team2_size, N * 50 + score_difference)

print "#", sum(first_team_weigths), sum(second_team_weights)

weights = first_team_weigths + second_team_weights
random.shuffle(weights)

for weight in weights:
	print weight

