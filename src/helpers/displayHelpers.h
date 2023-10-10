#include "esphome.h"
#include "esphome/core/log.h"

const char* getSocGlyph(
  float socNum
) {
  if (socNum >= 100) {
    return "󰁹";
  } else if (socNum >= 90) {
    return "󰂂";
  } else if (socNum >= 80) {
    return "󰂁";
  } else if (socNum >= 70) {
    return "󰂀";
  } else if (socNum >= 60) {
    return "󰁿";
  } else if (socNum >= 50) {
    return "󰁾";
  } else if (socNum >= 40) {
    return "󰁽";
  } else if (socNum >= 30) {
    return "󰁼";
  } else if (socNum >= 20) {
    return "󰁻";
  } else if (socNum >= 10) {
    return "󰁺";
  } else {
    return "󰂎";
  }
}

void invPrint(
  esphome::display::Display& it,
  int x,
  int y,
  esphome::font::Font* font,
  const char* text
) {
  it.filled_rectangle(x, y, it.get_width(), font->get_height(), COLOR_ON);
  it.print(x, y-1, font, COLOR_OFF, text);
}

const char* getWifiGlyph(
  float rssi
) {
  float wifiPercent = min(max(2 * (rssi + 100.0), 0.0), 100.0);
  if (wifiPercent >= 75) {
    return "󰤨";
  } else if (wifiPercent >= 50) {
    return "󰤥";
  } else if (wifiPercent >= 25) {
    return "󰤢";
  } else if (wifiPercent >= 0) {
    return "󰤟";
  } else {
    return "󰤫";
  }
}

float calculateCellRowPercent (float cellVolt) {
  //esphome::ESP_LOGW("dbg", "value %0.3f", (id(cell_volt_limit_max) - id(cell_volt_limit_min)));
  const float onePercentValue = (id(cell_volt_limit_max) - id(cell_volt_limit_min)) / 100;

  return (cellVolt - id(cell_volt_limit_min)) / onePercentValue;
}

void renderCellRow (
  esphome::display::Display& it,
  esphome::font::Font* font,
  int rowNum,
  float value
) {
  const int line_height = font->get_height();
  int t_y = (line_height - 2) * (rowNum - 1);

  const int fill_height = 3;
  const int fill_margin_top = 6;
  int fill_y_start = t_y + fill_margin_top;
  int fill_y_middle = fill_y_start + 1;
  const int fill_length_full = 38 - 7;
  int fill_length = std::nearbyint(fill_length_full * (calculateCellRowPercent(value) / 100));

  const int border_indent = 1;
  int border_y_start = fill_y_start - border_indent;
  int border_y_end = fill_y_start + fill_height + border_indent - 1;

  const int minVoltCell = esphome::id(min_voltage_cell).state;
  const int maxVoltCell = esphome::id(max_voltage_cell).state;

  it.print(0, t_y, font, std::to_string(rowNum).c_str());
  if (rowNum == minVoltCell || rowNum == maxVoltCell) {
    it.filled_rectangle(7, border_y_start - 2, 3, border_y_end - border_y_start + 4);
  } else {
    it.line(7, border_y_start, 7, border_y_end);
  }
  it.line(38, border_y_start, 38, border_y_end);
  it.filled_rectangle(7, fill_y_middle, fill_length_full, 1);
  it.filled_rectangle(7, fill_y_start, fill_length, fill_height);
  it.printf(64, t_y, font, TextAlign::TOP_RIGHT, "%3.2f", value);
}


