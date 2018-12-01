#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unordered_map>
#include <vector>
int main() {
	int current_frequency = 0;
	std::unordered_map<int, int> table;
	std::vector<int> changes;//(1000);
	bool found = false;
	//read file
	FILE *input;
	char* line = NULL;
	size_t len = 0;
	input = fopen("input_1.txt", "r");
	if (input == 0) {
		printf("Couldn't find the input file.");
		exit(1);
	}
	while (getline(&line, &len, input) != -1 ) {
		table.insert({current_frequency, 0});
		char *s;
		int val = (int)strtol(line, &s, 10);
		changes.push_back(val);
		current_frequency += val;
	}
	printf("part1: %d\n", current_frequency);
	int i = 0;
	int size = changes.size();
	while (!found) {
		current_frequency += changes[i % size];
		if (table.count(current_frequency)) {
			found = true;
		}
		table.insert({current_frequency, 0});
		i++;
	}
	printf("part2: %d\n", current_frequency);
	fclose(input);
	return 0;
}
