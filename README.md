# esphome-smart-battery
Control DIY smart battery using JBD BMS, external balancer. Monitor it with environment sensors and display.

<img src="images/header.png" alt="Project logo" height="300" width="auto">

## Features
- Grabs all BMS parameters by bluetooth and transfers it into Home Assistant
- Auto balance with external balancer with flexible logic setup
- Separate screen with button on battery case 
- Fancy card for lovelace
- Adjusted SoC calculation

## Hardware
[Detailed hardware description](pcb/README.md)

## Software
1) Create new project subdirectory within your ESPHome configuration directory (let it be `smart-battery`, for example) 
2) Copy the contents of the `src` repo folder to a newly created project directory.
3) Now, the `main.yaml` file must be located under `<esphome_config>/smart-battery`
4) Create file `smart-battery.yaml` in the esphome config directory root and copy contents of [example config](/examples/smart-battery.yaml)
5) Edit substitutions & customize `smart-battery.yaml`. You can add contents of [common_system](/examples/common_system.yaml) & [common_sensors](/examples/common_sensors.yaml) to this file or include them separately following the example.
6) Flash firmware to your ESP32

## Battery card
For easy battery control in Home Assistant, you can use the [following snippet](/battery-card/battery-card-example.yaml). It compiles all the essential battery sensors and controls in a compact manner. The following custom plugins are used: [bar-card](https://github.com/custom-cards/bar-card), [stack-in-card](https://github.com/custom-cards/stack-in-card), [tabbed-card](https://github.com/kinghat/tabbed-card), [text-divider-row](https://github.com/iantrich/text-divider-row), [canary](https://github.com/jcwillox/lovelace-canary).
<table border="0">
<tr>
<td valign="top"><img src="battery-card/screenshots/battery-card-tab1.png" alt="Battery card tab1 screenshot" width="250" height="auto"></td>
<td valign="top"><img src="battery-card/screenshots/battery-card-tab2.png" alt="Battery card tab2 screenshot" width="250" height="auto"></td>
<td valign="top"><img src="battery-card/screenshots/battery-card-tab3.png" alt="Battery card tab3 screenshot" width="250" height="auto"></td>
</tr>
</table>

## References & thanks
- This project is built around [syssi/esphome-jbd-bms](https://github.com/syssi/esphome-jbd-bms) at its core.
