@test "(Divider engine) Illegal Input test: input no enough arguments" {
  run ./build/calc
  [ "${lines[0]}" = "No enough argument values: please follow these two usages." ]
  [ "${lines[1]}" = "--------------------------------------------------" ]
  [ "${lines[2]}" = "Usage 1: calc <engine_name> <file_list>" ]
  [ "${lines[3]}" = "Usage 2: calc <engine_name> <list of integers>" ]
}

@test "(Divider engine) Illegal Input test: input wrong math engine" {
  run ./build/calc Sum 1 2
  [ "${lines[0]}" = "Invalid Math Engine: use either \"Multipiler\" or \"Divider\"." ]
}

@test "(Divider engine) Illegal Input test: input illegal *.txt file" {
  run ./build/calc Divider input 10
  [ "${lines[0]}" = "Inputs Error: illegal input files! Please give *.txt file." ]
}

@test "(Divider engine) Illegal Input test: input non-exist *.txt file" {
  run ./build/calc Divider input 10.txt
  [ "${lines[0]}" = "Input Error: Nonexistent *.txt file." ]
}

@test "(Divider engine) Integers inputs test: inputs 0 integer" {
  run ./build/calc Divider
  [ "${lines[0]}" = "No enough argument values: please follow these two usages." ]
  [ "${lines[1]}" = "--------------------------------------------------" ]
  [ "${lines[2]}" = "Usage 1: calc <engine_name> <file_list>" ]
  [ "${lines[3]}" = "Usage 2: calc <engine_name> <list of integers>" ]
}

@test "(Divider engine) Integers inputs test: inputs 1 integer" {
  run ./build/calc Divider 5
  [ "$output" = "5" ]
}

@test "(Divider engine) Integers inputs test: inputs 2 integers" {
  run ./build/calc Divider 10 2
  [ "$output" = "5" ]
}

@test "(Divider engine) Integers inputs test: contain non-intergers" {
  run ./build/calc Divider 10 a
  [ "$output" = "Inputs Error: illegal integers inputs!" ]
}


@test "(Divider engine) Integers inputs test: ZERO denominator" {
  run ./build/calc Divider 1 0
  [ "${lines[0]}" = "There is at least one ZERO denominator!" ]
}


@test "(Divider engine) List_files inputs test: input 0 list_file" {
  run ./build/calc Divider input
  [ "${lines[0]}" = "Inputs Error: no input files are given!" ]
}

@test "(Divider engine) List_files inputs test: input 1 list_file" {
  run ./build/calc Divider input ./data/1.txt
  [ "${lines[0]}" = "10" ]
}

@test "(Divider engine) List_files inputs test: input 2 list_files" {
  run ./build/calc Divider input ./data/1.txt ./data/2.txt
  [ "${lines[0]}" = "0.5" ]
}

@test "(Divider engine) List_files inputs test: contain non-integers" {
  run ./build/calc Divider input ./data/3.txt
  [ "${lines[0]}" = "2" ]
}


@test "(Divider engine) List_files inputs test: ZERO denominator" {
  run ./build/calc Divider input ./data/4.txt
  [ "${lines[0]}" = "There is at least one ZERO denominator!" ]
}


