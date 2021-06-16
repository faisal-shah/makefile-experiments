# remaking
This is experimenting with how GNU Make 'remakes' makefiles. Needed to look into this for some code generation stuff where a makefile and some source files were generated using a top level Makefile. In this project, module.c and module.mk are generated from an existing module.template file. module.template should be the only of the module.* files checked in to version control. The generated module.mk file is important to include in the top level makefile, as the variable output of it is added to the source list (stuff that needs to be built).

From [GNU Make Remaking](https://www.gnu.org/software/make/manual/make.html#Remaking-Makefiles)
> Sometimes makefiles can be remade from other files, such as RCS or SCCS files. If a makefile can be remade from other files, you probably want make to get an up-to-date version of the makefile to read in.
To this end, after reading in all makefiles make will consider each as a goal target and attempt to update it. If a makefile has a rule which says how to update it (found either in that very makefile or in another one) or if an implicit rule applies to it (see Using Implicit Rules), it will be updated if necessary. After all makefiles have been checked, if any have actually been changed, make starts with a clean slate and reads all the makefiles over again. (It will also attempt to update each of them over again, but normally this will not change them again, since they are already up to date.) Each restart will cause the special variable MAKE_RESTARTS to be updated (see Special Variables).

*Thanks to Giovanni Di Sirio for help*

### Other useful links
[GNU Make Include](https://www.gnu.org/software/make/manual/html_node/Include.html)

[StackOverflow: How Makefiles Are Remade - don't understand official documentation](https://stackoverflow.com/questions/65058553/how-makefiles-are-remade-dont-understand-official-documentation)

[remake - a GNU Make debugger!](https://remake.readthedocs.io/en/latest/index.html)

[ChibiOS forum thread](https://forum.chibios.org/viewtopic.php?f=2&t=5866&start=10)
