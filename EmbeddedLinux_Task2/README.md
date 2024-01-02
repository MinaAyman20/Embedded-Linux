# Embedded-Linux Task2


## Descripsion 
in this file we will Explain Sysroot and Binutil 
### Sysroot
compilers use many other files to generate their outputs. For instance, in order to generate programs, object files, and other sorts of outputs, C and C++ compilers search for headers and libraries.

By default, the compiler searches for those files in standard locations. However, we may want to use alternative directories. For instance, when cross-compiling binaries targeted at other platforms or when preparing experimental builds using non-standard headers and/or libraries.

The sysroot directory works as a root for headers and libraries. So, let’s consider that headers and libraries are searched by default under /usr/include/ and /usr/lib/, respectively. By defining the sysroot as /home/dir, the compiler will now look for headers and libraries under, respectively, /home/dir/usr/include/ and /home/dir/usr/lib/ instead.

### Binutil
Binutils is a collection of software development tools containing a linker, assembler and other tools to work with object files and archives.
Installed programs: addr2line, ar, as, c++filt, gprof, ld, nm, objcopy, objdump, ranlib, readelf, size, strings and strip
Installed libraries: libiberty.a, libbfd.[a,so] and libopcodes.[a,so]

ar ->  creates, modifies, and extracts from archives. An archive is a single file holding a collection of other files in a structure that makes it possible to retrieve the original individual files (called members of the archive).

as -> is an assembler. It assembles the output of gcc into object files.

gprof ->  displays call graph profile data.

ld -> is a linker. It combines a number of object and archive files into a single file, relocating their data and tying up symbol references.

nm ->  lists the symbols occurring in a given object file.

objcopy ->  is used to translate one type of object file into another.

objdump ->  displays information about the given object file, with options controlling what particular information to display. The information shown is mostly only useful to programmers who are working on the compilation tools.

ranlib ->  generates an index of the contents of an archive, and stores it in the archive. The index lists all the symbols defined by archive members that are relocatable object files.

readelf ->  displays information about elf type binaries.

size ->  lists the section sizes -- and the grand total -- for the given object files.

strings ->  outputs for each file given the sequences of printable characters that are of at least the specified length (defaulting to 4) For object files it prints by default only the strings from the initializing and loading sections. For other types of files it scans the whole file.

strip ->  discards symbols from object files.

libiberty ->  contains routines used by various GNU programs, including getopt, obstack, strerror, strtol and strtoul.

libbfd ->  is the Binary File Descriptor library.

libopcodes ->  is a library for dealing with opcodes. It is used for building utilities like objdump. Opcodes are the "readable text" versions of instructions for the processor.
