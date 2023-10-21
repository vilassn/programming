
## Swift Package and Application Setup

This guide demonstrates how to set up Swift packages and a simple Swift executable application.


## First Package

```sh
mkdir MyFirstPackage
cd MyFirstPackage
swift package init --type library
swift build
```

## Second Package (Optional)

```sh
cd ..
mkdir MySecondPackage
cd MySecondPackage
swift package init --type library
swift build
```

## Application

```sh
cd ..
mkdir MyApp
cd MyApp
swift package init --type executable
swift build
swift run
swift run -c release
```

## Clean Up

```sh
# Clean packages
swift package clean
swift build

# Run the application after cleaning (if applicable)
swift run
```

This guide helps you create Swift packages and run a basic Swift executable application. Customize and expand these packages and your application as needed.
