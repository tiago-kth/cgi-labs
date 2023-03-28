# Labs notes

## Notes to self

| Dúvidas                                   |
|-------------------------------------------|
| Preciso entender melhor o que o cmake faz.|
| Como o SDL funciona?                      |
| Pixel buffer?                             |

| References |                                              |
|------------|----------------------------------------------|
| SDL        | https://wiki.libsdl.org/SDL2/Introduction    |
|GLM | https://openframeworks.cc/documentation/glm/ |

Ver SDL2Auxiliary

## Lab 1 - old version

In order to check that everything works correctly please download the project files from the course website, open a terminal and go into your project folder. Then run CMake and if everything is set up correctly you should not receive any error. Run make to generate an executable from the project files.

What we did:

```bash
brew install sdl12-compat
brew install cmake
cmake .
make
./FirstLab
```

## Lab 2 - new version

### Setup

I am using CLion. With `cmake` and `sdl2` already installed with `brew`, everything seems to work fine, using the CLion building tools.

### Libraries

We are using SDL to set up a screen and draw on it. 



