# Make does not offer a recursive wildcard function, so here's one:
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
 
SRC=src
OUT=target
FLA=-Wno-write-strings
CXX=g++ $(FLA)
 
# Get all files from the source dir
FILES:=$(call rwildcard,$(SRC)/,*.cxx)
# Transform files (change .cpp to .o)
OBJ:=$(FILES:$(SRC)/%.cxx=$(OUT)/%.o)
 
# Get all folders
SRC_DIRS:=$(sort $(rwildcard,$(SRC)/*/))
# Transform tree structure to out dir
OUT_DIRS:=$(SRC_DIRS:$(SRC)%=$(OUT)%)
 
.PHONY: build
.SILENT:
 
build: $(OUT)/main
#build: $(OUT)/Test1 $(OUT)/Test2a $(OUT)/Test2b $(OUT)/Test2c $(OUT)/Test3a $(OUT)/Test3b $(OUT)/Test3c $(OUT)/Test3d $(OUT)/Test4 $(OUT)/Test5 $(OUT)/Test6a $(OUT)/Test6b $(OUT)/Test6c $(OUT)/Test6d $(OUT)/Test6e $(OUT)/Test7
 
$(OUT)/main: main.cxx $(OBJ)
	echo Compiling $@...
	$(CXX) -o $@ $^
 
$(OUT)/Test%: Test%.cxx $(OBJ)
	echo Compiling $@...
	$(CXX) -o $@ $^
 
$(OUT)/%.o: $(SRC)/%.cxx $(SRC)/%.h
	echo Compiling $@...
	$(CXX) -c -o $@ $<