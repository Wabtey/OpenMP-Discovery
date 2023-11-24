#
# Link
#

CFLAGS = # -Wall -g


# -------------------------------- Aggregation ------------------------------- #

aggregation: compile_aggregation execute_aggregation

execute_aggregation:
	padsp ./src/exec/aggregation

compile_aggregation:
	mkdir -p ./src/exec
	gcc $(CFLAGS) -o ./src/exec/aggregation ./src/aggregation-openmp.c -fopenmp

# -------------------------------- Map Reduce -------------------------------- #

mapreduce: compile_mapreduce execute_mapreduce

execute_mapreduce:
	padsp ./src/exec/mapreduce

compile_mapreduce:
	mkdir -p ./src/exec
	gcc $(CFLAGS) -o ./src/exec/mapreduce ./src/mapreduce-openmp.c -fopenmp

# ------------------------------- Remove files ------------------------------- #

clean :
	rm src/exec/*