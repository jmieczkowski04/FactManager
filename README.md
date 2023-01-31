# Fact Manager

Fact Manager is Unreal&reg; Engine plugin. Contains single module containing single uclass implementing fact manager. Just install, create an object of FactManager, initialize and use.

## Documentation

Fact Manager stores API docs in UE documentation system based on JavaDoc. Because it is easy accessible and most IDEs understand these comments, I decided not to generate the documentation.

## Feauters

- All facts are named using FName and this is the only way you can access them
- Every fact has an integer value
- Value can be overridden or sumed when modifing a fact
- It is possible for a fact to be valid for a certain period of time

## Plans

The code will be polished and probably reused as a part of my long term project, non-linear quest system plugin.
