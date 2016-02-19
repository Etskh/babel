# babel



# Install

## External Dependencies

These are all the dependencies inside the `extern` folder. They are compiled
into their own library to improve compile times.

#### Duktape

_This step is already committed into the source-tree. Later, this might not be the case, but right now, you do not need to add or remove files from `extern`_

~~Install [Duktape](http://duktape.org/) into the `extern` folder. Certain sources link to them.~~

## Frameworks

These are frameworks that the build system expects to exist globally. You might need to install them from source, depending on your system.

#### Awesomium

Install [Awesomium](http://www.awesomium.com/) from their website... cmake _should_ find it. We're using 1.7, and haven't tested with any other version.

#### SDL2

Install [SDL2](https://www.libsdl.org/download-2.0.php) from the website... cmake _should_ find it. We're using version 2, built from source, and haven't tested with any other version.

## Tools

 * [CMake](https://cmake.org/) to compile
 * The interface uses the [LessCSS](http://lesscss.org/) compiler - use `npm install less`
 * _optional_ python 2.7 to lint
 * _optional_ Doxygen to generate documentation

# Compilation

Babel uses CMake and C++11.

Create and go to the `build` directory.

Run `cmake ..` which should generate the makefiles

Then `make -j12` or something which will compile the application

Run from that folder (it should be `./Babel`)



# Development Notes

## Linting

At the moment, the closest convention is the Google Code convention, so linting
is done with `cpplint.py`, with several changes to the filters, and some changes
to come in the roadmap.

Since _cpplint.py_ is already a filename that has expectations about how it functions, linting for this project should be done with the `./lint` executable shell-script in the project directory.

That way, changes can be make transparently to how it lints, and the command will always stay the same.

## Documentation

Doxygen is used to generate the inline documentation. Its purpose is more for refreshing with the API, not to be a complete how-to-get-started tutorial.

To make documentation from the source code, run `doxygen` from the project directory.


# Contributors

Etskh (http://github.com/Etskh) (http://jamescodes.ca)
