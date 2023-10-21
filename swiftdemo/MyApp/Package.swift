// swift-tools-version:5.5
import PackageDescription

let package = Package(
    name: "MyApp",
    dependencies: [
        .package(path: "../MyFirstPackage"),
        .package(path: "../MySecondPackage"),
    ],
    targets: [
        .executableTarget(
            name: "MyApp",
            dependencies: ["MyFirstPackage", "MySecondPackage"]
            // linkerSettings: [.linkedFramework("Accelerate"),]
            resources: [
                .copy("Resources")
            ]
        ),
    ]
)
