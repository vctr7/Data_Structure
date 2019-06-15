// Experiment.h
// Header file for Experiment.c


typedef enum { INORDER, RANDOM } BuildMethod;

typedef enum { TOTALBUILD, SEARCHFORMAX, SEARCHFORONE, RANDOMSEARCH } TimingMethod;

typedef enum { NOREPEAT, REPEAT } RepeatMethod;

typedef
struct EXPERIMENTPARAMETERS
{
	TreeType treeType;
	BuildMethod buildMethod;
	TimingMethod timingMethod;
	RepeatMethod repeatMethod;
} ExperimentParameters;


SearchableTree ** createTreeArray(int numTrees);
ExperimentParameters * configureExperiment(void);
void growTree(SearchableTree * tree, ExperimentParameters * params, long size);
void buildTrees(SearchableTree ** treeArray, ExperimentParameters * params, 
		long size, int numTrees);
void searchOneTree(SearchableTree * tree, ExperimentParameters * params);
void searchTrees(SearchableTree ** treeArray, Timer * timer, 
		ExperimentParameters * params, int numTrees);
void runExperiment(SearchableTree ** treeArray, Timer * timer, 
		ExperimentParameters * params, long size, int numTrees);

