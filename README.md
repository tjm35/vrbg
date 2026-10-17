# vrbg
Command line tool to use arbitrary play area background images on the Steam Frame.

## Installation

* Download the `vrbg` executable from the latest "Releases" page to your Steam Frame.
* Navigate to the download folder in a console window and run `chmod a+x vrbg` to make the app executable.

## Usage
`./vrbg [path_to_background_image]`

Run without arguments to display the path to the current background image. Pass an image filename as an argument to immediately set that image as the play area background.

Background images must be 360° skyboxes in equirectangular format. Jpeg and PNG formats have been tested successfully. For reference Steam's built-in skyboxes are various sizes, from 2048x1024 up to 8192x4096.

Background images will only be used if the Play Area Environment Style is set to "image". The tool will warn the user if this is not the case.

Background images will not be shown if the passthrough camera is in use. The tool will not warn the user about this.

## Building

In case you want to build this yourself:

* Clone the repository to a folder on your Steam Frame.
* Run `make` in that folder.

All necessary prerequisites should already be on the Frame as standard.
