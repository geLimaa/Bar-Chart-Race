#include "include/UserInput.hpp"
#include "include/Reader.hpp"
#include "include/Animation.hpp"

int main(int argc, char* argv[]){
    UserInput input;
    Config config = input.parse(argc, argv);
    Reader reader;

    Database db = reader.readFile(config.filename);
    Animation animation;

    animation.play(db, config.max_bars, config.fps);
}
