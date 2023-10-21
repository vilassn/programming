// swift-tools-version:5.5
import PackageDescription

let package = Package(
    name: "MyFirstPackage",
    products: [
        .library(name: "MyFirstPackage", targets: ["MyFirstPackage"]),
    ],
    dependencies: [
        // Add your dependencies here, if any.
    ],
    targets: [
        .target(name: "MyFirstPackage", dependencies: []),
    ]
)
