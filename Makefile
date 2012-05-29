
BIN = bin

BUILD = build

OPENCV_INCLUDE = `pkg-config opencv --cflags`
OPENCV = `pkg-config opencv --cflags --libs`

OBJECTS = $(BUILD)/main.o \
			 $(BUILD)/core/core.o \
			 $(BUILD)/detection/detection.o \
			 $(BUILD)/detection/thermal.o \
			 $(BUILD)/gui/configuration.o \
		    $(BUILD)/gui/core.o \
          $(BUILD)/gui/main_menu.o \
			 $(BUILD)/structures/Program_Options.o \
			 $(BUILD)/utilities/string_utilities.o

HEADERS = src/alignment/alignment.hpp \
			 src/core/core.hpp \
			 src/detection/detection.hpp \
			 src/gui/gui.hpp \
			 src/structures/Program_Options.hpp \
			 src/utilities/string_utilities.hpp

all: $(BIN)/VLTIF


######################################### 
#          PRIMARY EXECUTABLE           #
#########################################
$(BIN)/VLTIF: $(OBJECTS) $(BUILD) $(BUILD)/gui $(BUILD)/utilities
	g++ -o $@ $(OBJECTS) $(OPENCV) -lncurses



$(BUILD)/main.o: src/main.cpp $(BUILD)/gui $(BUILD)/utilities $(HEADERS)
	g++ $< -c -o $@ $(OPENCV_INCLUDE)

$(BUILD)/core/core.o: src/core/core.cpp $(BUILD)/core $(HEADERS)
	g++ $< -c -o $@

$(BUILD)/detection/detection.o: src/detection/detection.cpp $(BUILD)/detection $(HEADERS)
	g++ $< -c -o $@ 

$(BUILD)/detection/thermal.o: src/detection/thermal.cpp $(BUILD)/detection $(HEADERS)
	g++ $< -c -o $@

$(BUILD)/gui/configuration.o: src/gui/configuration.cpp $(BUILD)/gui $(HEADERS)
	g++ $< -c -o $@

$(BUILD)/gui/core.o: src/gui/core.cpp $(HEADERS)
	g++ $< -c -o $@

$(BUILD)/gui/main_menu.o: src/gui/main_menu.cpp $(HEADERS)
	g++ $< -c -o $@ $(OPENCV_INCLUDE)

$(BUILD)/structures/Program_Options.o: src/structures/Program_Options.cpp $(BUILD)/structures $(HEADERS)
	g++ $< -c -o $@ 

$(BUILD)/utilities/string_utilities.o: src/utilities/string_utilities.cpp $(HEADERS)
	g++ $< -c -o $@ 


check:
	mkdir -p build
	g++ src/test/unit_test.cpp -o build/unit_test
	./build/unit_test

clean:
	rm -rf $(BUILD)/*


$(BIN):
	@mkdir -p $(BIN)

$(BUILD):
	@mkdir -p $(BUILD)

$(BUILD)/core:
	@mkdir -p $(BUILD)/core

$(BUILD)/detection:
	@mkdir -p $(BUILD)/detection

$(BUILD)/gui:
	@mkdir -p $(BUILD)/gui

$(BUILD)/structures:
	@mkdir -p $(BUILD)/structures

$(BUILD)/utilities:
	@mkdir -p $(BUILD)/utilities

