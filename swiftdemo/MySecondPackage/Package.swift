// swift-tools-version:5.5
import PackageDescription

let package = Package(
    name: "MySecondPackage",
    products: [
        .library(name: "MySecondPackage", targets: ["MySecondPackage"]),
    ],
    dependencies: [
        .package(path: "../MyFirstPackage"),
    ],
    targets: [
        .target(name: "MySecondPackage", dependencies: ["MyFirstPackage"]),
    ]
)
