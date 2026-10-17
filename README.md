# vrbg
Command line tool to use arbitrary play area backgrounds on the Steam Frame.

## Usage
`vrbg [path_to_background_image]`
Run without arguments to display the path to the current background image. Pass an image filename as an argument to immediately set that image as the play area background.
Background images must be 360° skyboxes in equirectangular format. Jpeg and PNG formats have been tested successfully. Steam's built-in skyboxes are various sizes, up to 8192x4096.
Background images will only be used if the Play Area Environment Style is set to "image". The tool will warn the user if this is not the case.
