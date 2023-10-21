import json

class JsonDataParser:
    def __init__(self, json_string):
        self.data = json.loads(json_string)

    def get_rules(self):
        return [rule["name"] for rule in self.data["mRules"]]

    def get_ranges(self):
        return [{
            "name": r["name"],
            "value": r["value"],
            "selected": r["selected"]
        } for r in self.data["mRanges"]]

    def get_bookmarks(self):
        return [bookmark["name"] for bookmark in self.data["mBookmarks"]]

    def get_intervals(self):
        return [{
            "name": interval["name"],
            "value": interval["value"],
            "selected": interval["selected"]
        } for interval in self.data["mIntervals"]]

    def get_indicators(self):
        return [{
            "name": indicator["name"],
            "selected": indicator["selected"],
            "type": indicator["type"],
            "params": indicator["params"]
        } for indicator in self.data["mIndicators"]]

    def get_chart_types(self):
        return [{
            "name": chart_type["name"],
            "value": chart_type["value"],
            "selected": chart_type["selected"]
        } for chart_type in self.data["mChartTypes"]]

    def get_series_loaders(self):
        return [{
            "name": loader["name"],
            "selected": loader["selected"],
            "loaderType": loader["loaderType"]
        } for loader in self.data["mSeriesLoaders"]]

    def get_last_bar_loaders(self):
        return [{
            "name": loader["name"],
            "selected": loader["selected"],
            "loaderType": loader["loaderType"]
        } for loader in self.data["mLastBarLoaders"]]

    def get_setting_map(self):
        return [{
            "name": setting_name,
            "value": setting_info["value"],
            "selected": setting_info["selected"]
        } for setting_name, setting_info in self.data["mSettingMap"].items()]

    def get_chart_setting_map(self):
        return [{
            "name": setting_name,
            "value": setting_info["value"],
            "selected": setting_info["selected"]
        } for setting_name, setting_info in self.data["mChartSettingMap"].items()]

# Example usage
json_string = '''{
  "mRules": [
    {
      "name": "()"
    },
    {
      "name": "and"
    },
    {
      "name": "or"
    },
    {
      "name": "xor"
    },
    {
      "name": "negation"
    },
    {
      "name": "boolean"
    },
    {
      "name": "over"
    },
    {
      "name": "under"
    },
    {
      "name": "crossedUp"
    },
    {
      "name": "crossedDown"
    },
    {
      "name": "stopLoss"
    },
    {
      "name": "stopGain"
    },
    {
      "name": "isEqual"
    },
    {
      "name": "isFalling"
    },
    {
      "name": "isRising"
    },
    {
      "name": "isHighest"
    },
    {
      "name": "isLowest"
    }
  ],
  "mRanges": [
    {
      "name": "1d",
      "value": 86400,
      "selected": false
    },
    {
      "name": "5d",
      "value": 432000,
      "selected": false
    },
    {
      "name": "2w",
      "value": 1296000,
      "selected": false
    },
    {
      "name": "2m",
      "value": 5616000,
      "selected": false
    },
    {
      "name": "1y",
      "value": 31622400,
      "selected": false
    },
    {
      "name": "5y",
      "value": 158112000,
      "selected": false
    }
  ],
  "mBookmarks": [
    {
      "name": "https://kite.zerodha.com"
    },
    {
      "name": "https://www.moneycontrol.com"
    },
    {
      "name": "https://www.thecalculatorsite.com"
    },
    {
      "name": "https://sites.google.com/view/wavesignal"
    },
    {
      "name": "https://zerodha.com/brokerage-calculator"
    }
  ],
  "mIntervals": [
    {
      "name": "15m",
      "value": 900,
      "selected": false
    },
    {
      "name": "1h",
      "value": 3600,
      "selected": false
    },
    {
      "name": "1d",
      "value": 86400,
      "selected": true
    },
    {
      "name": "1w",
      "value": 604800,
      "selected": false
    }
  ],
  "mIndicators": [
    {
      "name": "Close : {period\u003d0}",
      "selected": false,
      "type": "IND_CLOSELN",
      "params": {
        "period": 0
      }
    },
    {
      "name": "SMA10 : {period\u003d10}",
      "selected": false,
      "type": "IND_SMA",
      "params": {
        "period": 10
      }
    },
    {
      "name": "EMA20 : {period\u003d20}",
      "selected": true,
      "type": "IND_EMA",
      "params": {
        "period": 20
      }
    },
    {
      "name": "ZTrend : {average\u003d3, streak\u003d7}",
      "selected": false,
      "type": "IND_ZTREND",
      "params": {
        "average": 3,
        "streak": 7
      }
    },
    {
      "name": "ZTrendOverlay : {average\u003d3, streak\u003d7}",
      "selected": false,
      "type": "IND_ZTRENDOL",
      "params": {
        "average": 3,
        "streak": 7
      }
    },
    {
      "name": "SuperTrend : {period\u003d7, multiplier\u003d3}",
      "selected": true,
      "type": "IND_SUPERTREND",
      "params": {
        "period": 7,
        "multiplier": 3
      }
    },
    {
      "name": "SupResPCOI : {high\u003d1, mid\u003d1}",
      "selected": true,
      "type": "IND_SRPCOI",
      "params": {
        "high": 1,
        "mid": 1
      }
    },
    {
      "name": "MACD : {fast\u003d12, slow\u003d26, signal\u003d9}",
      "selected": true,
      "type": "IND_MACD",
      "params": {
        "fast": 12,
        "slow": 26,
        "signal": 9
      }
    },
    {
      "name": "Awesome : {period\u003d14}",
      "selected": false,
      "type": "IND_AWESOME",
      "params": {
        "period": 14
      }
    },
    {
      "name": "Fisher : {period\u003d14, signal\u003d3}",
      "selected": true,
      "type": "IND_FISHER",
      "params": {
        "period": 14,
        "signal": 3
      }
    },
    {
      "name": "RSI : {period\u003d14}",
      "selected": false,
      "type": "IND_RSI",
      "params": {
        "period": 14
      }
    },
    {
      "name": "StochRSI : {period\u003d14}",
      "selected": false,
      "type": "IND_STOCHRSI",
      "params": {
        "period": 14
      }
    },
    {
      "name": "ADX : {period\u003d14}",
      "selected": false,
      "type": "IND_ADX",
      "params": {
        "period": 14
      }
    },
    {
      "name": "ATR : {period\u003d14}",
      "selected": false,
      "type": "IND_ATR",
      "params": {
        "period": 14
      }
    },
    {
      "name": "ROC : {period\u003d14}",
      "selected": false,
      "type": "IND_ROC",
      "params": {
        "period": 14
      }
    },
    {
      "name": "BB : {period\u003d14}",
      "selected": false,
      "type": "IND_BB",
      "params": {
        "period": 14
      }
    },
    {
      "name": "STDDEV : {period\u003d14}",
      "selected": false,
      "type": "IND_STDDEV",
      "params": {
        "period": 14
      }
    },
    {
      "name": "Volume : {period\u003d3}",
      "selected": false,
      "type": "IND_VOLUME",
      "params": {
        "period": 3
      }
    },
    {
      "name": "OBV : {period\u003d14}",
      "selected": false,
      "type": "IND_OBV",
      "params": {
        "period": 14
      }
    },
    {
      "name": "ROCV : {period\u003d14}",
      "selected": false,
      "type": "IND_ROCV",
      "params": {
        "period": 14
      }
    },
    {
      "name": "VolumeOsci : {fast\u003d12, slow\u003d26}",
      "selected": false,
      "type": "IND_VOLUMEOSC",
      "params": {
        "fast": 12,
        "slow": 26
      }
    },
    {
      "name": "CombinedOI : {period\u003d0}",
      "selected": false,
      "type": "IND_COMBOI",
      "params": {
        "period": 0
      }
    },
    {
      "name": "DonchianChannels : {period\u003d14}",
      "selected": false,
      "type": "IND_DONCHIAN",
      "params": {
        "period": 14
      }
    }
  ],
  "mChartTypes": [
    {
      "name": "CandleStick",
      "value": 0,
      "selected": true
    },
    {
      "name": "Heikin Ashi",
      "value": 0,
      "selected": false
    },
    {
      "name": "Line",
      "value": 0,
      "selected": false
    }
  ],
  "mSeriesLoaders": [
    {
      "name": "NSE",
      "selected": true,
      "loaderType": "LOADER_NSE"
    },
    {
      "name": "Yahoo",
      "selected": false,
      "loaderType": "LOADER_YAHOO"
    },
    {
      "name": "ETimes",
      "selected": false,
      "loaderType": "LOADER_ET"
    }
  ],
  "mLastBarLoaders": [
    {
      "name": "NSE",
      "selected": false,
      "loaderType": "LOADER_NSE"
    },
    {
      "name": "Yahoo",
      "selected": false,
      "loaderType": "LOADER_YAHOO"
    },
    {
      "name": "ETimes",
      "selected": true,
      "loaderType": "LOADER_ET"
    }
  ],
  "mSettingMap": {
    "ST_OIUPDATE": {
      "name": "OIUpdate",
      "value": 0,
      "selected": false
    },
    "ST_OFFLINEMODE": {
      "name": "Offline",
      "value": 0,
      "selected": false
    },
    "ST_AUTOSCANMODE": {
      "name": "AutoScan",
      "value": 0,
      "selected": false
    },
    "ST_AUTOSCANGRACE": {
      "name": "AutoScanGrace",
      "value": 15,
      "selected": false
    },
    "ST_AUTOSCANINTRVL": {
      "name": "AutoScanIntrvl",
      "value": 60,
      "selected": false
    },
    "ST_AUTOTRADEMODE": {
      "name": "AutoTrade",
      "value": 0,
      "selected": false
    },
    "ST_AUTOTRADETIMING": {
      "name": "AutoTradeTiming",
      "value": 325,
      "selected": false
    },
    "ST_STGSCRIPTMODE": {
      "name": "UseTextStg",
      "value": 0,
      "selected": true
    },
    "ST_EXPNEAR": {
      "name": "near",
      "value": 0,
      "selected": true
    },
    "ST_EXPNEXT": {
      "name": "next",
      "value": 0,
      "selected": true
    },
    "ST_EXPFAR": {
      "name": "far",
      "value": 0,
      "selected": true
    },
    "ST_LIVEMODE": {
      "name": "Live",
      "value": 0,
      "selected": true
    },
    "ST_PRACTISEDATE": {
      "name": "20190525",
      "value": 0,
      "selected": false
    },
    "ST_USERID": {
      "name": "user.trial123@xyz.com",
      "value": 0,
      "selected": false
    },
    "ST_SECRETCODE": {
      "name": "PUFBQUJMUVVYY2d3",
      "value": 0,
      "selected": false
    },
    "ST_LOADBARS": {
      "name": "LoadBars",
      "value": 400,
      "selected": false
    },
    "ST_SCANBARS": {
      "name": "ScanBars",
      "value": 100,
      "selected": false
    },
    "ST_PROFTRGT": {
      "name": "ProfitTarget",
      "value": 4,
      "selected": false
    },
    "ST_STOPLOSS": {
      "name": "Stoploss",
      "value": 3,
      "selected": false
    },
    "ST_ZTSTREAK": {
      "name": "ZT Streak",
      "value": 7,
      "selected": false
    },
    "ST_ZTAVG": {
      "name": "ZT Average",
      "value": 3,
      "selected": false
    }
  },
  "mChartSettingMap": {
    "CHARTST_INT1H": {
      "name": "1h",
      "value": 3600,
      "selected": false
    },
    "CHARTST_INT1D": {
      "name": "1d",
      "value": 86400,
      "selected": true
    },
    "CHARTST_INT1W": {
      "name": "1w",
      "value": 604800,
      "selected": false
    },
    "CHARTST_CS": {
      "name": "CandleStick",
      "value": 0,
      "selected": true
    },
    "CHARTST_HA": {
      "name": "Heikin Ashi",
      "value": 0,
      "selected": false
    },
    "CHARTST_ZT": {
      "name": "ZTrend",
      "value": 0,
      "selected": false
    },
    "CHARTST_LN": {
      "name": "Line",
      "value": 0,
      "selected": false
    }
  }
}'''  # Your JSON string here
parser = JsonDataParser(json_string)

print("Rules:", parser.get_rules())
print("Ranges:", parser.get_ranges())
print("Bookmarks:", parser.get_bookmarks())
print("Intervals:", parser.get_intervals())
print("Indicators:", parser.get_indicators())
print("Chart Types:", parser.get_chart_types())
print("Series Loaders:", parser.get_series_loaders())
print("Last Bar Loaders:", parser.get_last_bar_loaders())
print("Setting Map:", parser.get_setting_map())
print("Chart Setting Map:", parser.get_chart_setting_map())
