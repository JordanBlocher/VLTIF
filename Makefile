
BIN = bin

BUILD = build

OPENCV_INCLUDE = `pkg-config opencv --cflags`
OPENCV = `pkg-config opencv --cflags --libs`

OBJECTS = $(BUILD)/main.o \
		    $(BUILD)/core.o \
          $(BUILD)/main_menu.o \
			 $(BUILD)/string_utilities.o

######################################### 
#          PRIMARY EXECUTABLE           #
#########################################
$(BIN)/VLTIF: $(OBJECTS)
	g++ -o $@ $(OBJECTS) $(OPENCV) -lncurses



$(BUILD)/main.o: src/main.cpp
	g++ $< -c -o $@ $(OPENCV_INCLUDE)

$(BUILD)/core.o: src/gui/core.cpp
	g++ $< -c -o $@

$(BUILD)/main_menu.o: src/gui/main_menu.cpp
	g++ $< -c -o $@ $(OPENCV_INCLUDE)

$(BUILD)/string_utilities.o: src/utilities/string_utilities.cpp
	g++ $< -c -o $@ 


check:
	mkdir -p build
	g++ src/test/unit_test.cpp -o build/unit_test
	./build/unit_test

clean:
	rm -rf $(BUILD)/*.o
	rm $(BUILD)/VLTIF


