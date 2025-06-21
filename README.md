# Image Processing in C Language

A comprehensive command-line image processing application built in C, featuring multiple image filtering and transformation capabilities using the STB image library.

## Overview

This project implements a basic photo editor that runs directly in the terminal, offering various image manipulation features including color extraction, format conversion, cropping, and artistic filters. The application processes PNG and JPG images with support for RGB and RGBA channels.

## Features

- **Image Cropping**: Extract specific regions from images with user-defined coordinates
- **RGB Component Extraction**: Isolate individual color channels (Red, Green, Blue)
- **Grayscale Conversion**: Convert color images to grayscale using luminance weighting
- **Black & White Conversion**: Create high-contrast binary images
- **Sepia Filter**: Apply vintage sepia tone effects
- **Color Channel Manipulation**: Swap and rearrange RGB components for creative effects

## Technical Implementation

The application utilizes the STB image library for efficient image loading and saving operations. Memory management is handled through dynamic allocation with proper cleanup procedures. The core processing algorithms implement standard computer vision techniques:

- **Grayscale Formula**: `0.299*R + 0.587*G + 0.114*B` (luminance-based conversion)
- **Sepia Transform**: Matrix-based color transformation for vintage effects
- **Binary Threshold**: 128-value threshold for black and white conversion
- **Pointer Arithmetic**: Efficient pixel-level manipulation using direct memory access

## Project Structure

```
├── Final.c              # Main application with all processing functions
├── Image.h              # Image structure and function declarations
├── utils.h              # Utility functions and error handling macros
├── stb_image/           # STB image library headers
├── Sample 1/            # Sample input images
├── Sample 2/            # Additional test images
└── Sample 3/            # Processed output examples
```

## Sample Results

### Original Image and Processed Outputs (Sample 3)

![Original Image](Sample%203/Original%20Image.jpg)

### Color Component Extractions
![Red Component](Sample%203/Red.png)
![Green Component](Sample%203/Green.png) 
![Blue Component](Sample%203/Blue.png)

### Image Transformations
![Grayscale](Sample%203/Grayscale.png)
![Black and White](Sample%203/Black_and_White.jpg)
![Sepia Filter](Sample%203/Sepia.png)

### Color Channel Manipulations
![BG Swap](Sample%203/BG.png)
![RGB Transformation 1](Sample%203/RGB1.png)
![RGB Transformation 2](Sample%203/RGB2.png)

### Cropping Example
![Cropped Image](Sample%203/Crop.png)

## Compilation and Usage

```bash
# Compile the project
gcc Final.c -o image_processor -lm

# Run the application
./image_processor
```

The program will display a menu with 6 options:
1. Crop an image
2. Extract RGB components
3. Convert to grayscale
4. Convert to black and white
5. Apply sepia filter
6. Interchange color components

## Dependencies

- **STB Image Library**: Single-header library for image loading/saving
- **Standard C Libraries**: stdio.h, stdlib.h, math.h
- **GCC Compiler**: With math library linking (-lm flag)

## Supported Formats

- **Input**: PNG, JPG/JPEG
- **Output**: PNG, JPG
- **Color Modes**: RGB, RGBA (with alpha channel preservation)

## Technical Highlights

- Efficient memory management with proper allocation and deallocation
- Support for both 3-channel (RGB) and 4-channel (RGBA) images
- Pixel-level processing using pointer arithmetic for optimal performance
- Comprehensive error handling and validation
- Modular design with reusable image processing functions