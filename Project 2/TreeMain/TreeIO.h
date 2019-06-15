// TreeIO.h
// Header file for TreeIO.c



TreeType chooseTreeType(void);
BuildMethod chooseBuildMethod(void);
TimingMethod chooseTiming(void);
RepeatMethod chooseRepeat(void);
int chooseTreeSize(void);
void printTotalBuildTime(Timer * timer, int numTrees);
void printSearchTime(Timer * timer, ExperimentParameters * params, int numTrees);
void printResults(Timer * timer, ExperimentParameters * params, int numTrees);

