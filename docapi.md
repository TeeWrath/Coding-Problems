# Hotel Booking API Documentation

## Hotel Routes

### 1. Get Hotel Top Information
**Route:** GET `/hotels/top/hotel`  
**Controller Function:** `getHotelTopInfo`  
**Middleware:** None  
**Description:** Fetches comprehensive information about a specific hotel including basic details, contact information, access details, policies, and price comparison settings.

**Query Parameters:**
| Parameter | Description | Example |
|-----------|-------------|---------|
| `hotelId` | Unique identifier of the hotel | 23 |

**Input:**
No JSON body required.

**Output JSON (Success):**
```json
{
  "response_code": 200,
  "http_response_status": 200,
  "message": "Top hotel information fetched",
  "data": {
    "Result": {
      "Status": "OK",
      "Code": 200
    },
    "HotelMaster": {
      "BookingSiteDisable": 1,
      "LastMngDate": "2026-10-31",
      "UsingMetaSearch": 0,
      "SiteId": 169
    },
    "Hotel": {
      "Name": "天海の城",
      "CatchCopy": "",
      "Type": 0,
      "Address": " 長崎県西海市崎戸町本郷362-1",
      "PhoneNum": "123-4567-8901",
      "FaxNum": "",
      "AccessOverview": "JR佐世保駅から車で1時間",
      "NearestStation": "JR佐世保駅",
      "Location": [],
      "PointOfDep": "",
      "OtherThanCar": "",
      "NearestIc": "",
      "IcAccess": "",
      "Parking": null,
      "Pickup": null,
      "BathingTax": "",
      "BedTax": "",
      "Remarks": "",
      "Header": "",
      "Footer": "",
      "Copyright": "",
      "TermsType": 0,
      "Terms": "https://example.com/",
      "PrivacyPolicyType": 0,
      "PrivacyPolicy": "https://example.com/",
      "TrackingId": "",
      "CardPaySrv": 2,
      "AvailableVendor": 0,
      "MailAddress": "test@example.com",
      "Latitude": null,
      "Longitude": null,
      "SendMailToCustomer": 1,
      "ChildrenSetting": [],
      "Pictures": [],
      "StayLimitMin": 0,
      "StayLimitMax": 0,
      "RoomLimitMin": 1,
      "RoomLimitMax": 10,
      "AdultLimitMin": 1,
      "AdultLimitMax": 10,
      "ChildLimitMin": 1,
      "ChildLimitMax": 10,
      "TagManagerTermsAgree": 0,
      "TagManagerGoogle": null,
      "GfblBookingFormUrl": null,
      "AreaID": 0,
      "LoginScreenType": 0,
      "ShowBestPrice": 0,
      "TotalPriceOrder": 0,
      "OptionDisplayFlag": 0,
      "ShowDateOfStayAsSelected": 0,
      "PriceComparisonSettings": [
        {
          "SiteId": 1,
          "SiteName": "楽天トラベル",
          "UsePriceComparison": 0
        },
        {
          "SiteId": 2,
          "SiteName": "じゃらん",
          "UsePriceComparison": 0
        },
        {
          "SiteId": 3,
          "SiteName": "Booking.com",
          "UsePriceComparison": 0
        },
        {
          "SiteId": 4,
          "SiteName": "Expedia",
          "UsePriceComparison": 0
        },
        {
          "SiteId": 5,
          "SiteName": "一休.com",
          "UsePriceComparison": 0
        },
        {
          "SiteId": 7,
          "SiteName": "Agoda",
          "UsePriceComparison": 0
        }
      ]
    },
    "MemberSetting": {
      "Type": 0,
      "Items": []
    }
  }
}
```

**Notes:**
- Returns comprehensive hotel information including multilingual support
- Includes price comparison settings with major booking platforms
- Provides hotel policies, contact information, and access details
- Contains room capacity limits and booking configuration settings

---

### 2. Get Room Plan Information
**Route:** GET `/hotels/roomplan/room`  
**Controller Function:** `getRoomPlan`  
**Middleware:** None  
**Description:** Fetches all available rooms for a specific hotel with detailed room information including amenities, equipment, capacity, and associated plan IDs.

**Query Parameters:**
| Parameter | Description | Example |
|-----------|-------------|---------|
| `hotelId` | Unique identifier of the hotel | 23 |

**Input:**
No JSON body required.

**Output JSON (Success):**
```json
{
  "response_code": 200,
  "http_response_status": 200,
  "message": "Rooms fetched successfully",
  "data": {
    "Result": {
      "Status": "OK",
      "Code": 200
    },
    "Rooms": [
      {
        "RoomId": 1437,
        "RoomName": "部屋1",
        "RoomNameEn": "Test Room 1",
        "RoomNameTw": null,
        "RoomNameCn": null,
        "RoomNameKr": null,
        "RoomDescription": "部屋1の詳細です。",
        "RoomDescriptionEn": "Test Room 1",
        "RoomDescriptionTw": null,
        "RoomDescriptionCn": null,
        "RoomDescriptionKr": null,
        "RoomSize": 12,
        "RoomSizeUnit": 0,
        "MinPax": 1,
        "MaxPax": 10,
        "ChildCapacitySetting": null,
        "AcceptableChildPax": null,
        "RoomCategory": 1,
        "RoomType": 1,
        "Grade": 0,
        "View": 0,
        "Equipment": [
          0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29
        ],
        "Amenity": [
          0,1,2,3,4,5,6,7,8,9,10,11,12
        ],
        "Feature": [],
        "Reason": [],
        "AcceptanceCondition": [],
        "Pictures": [],
        "PlanIds": [1218,1220]
      },
      {
        "RoomId": 1438,
        "RoomName": "部屋2",
        "RoomNameEn": "Test Room 2",
        "RoomNameTw": null,
        "RoomNameCn": null,
        "RoomNameKr": null,
        "RoomDescription": "部屋2の詳細です。",
        "RoomDescriptionEn": "Test Room 2",
        "RoomDescriptionTw": null,
        "RoomDescriptionCn": null,
        "RoomDescriptionKr": null,
        "RoomSize": 15,
        "RoomSizeUnit": 0,
        "MinPax": 2,
        "MaxPax": 8,
        "ChildCapacitySetting": null,
        "AcceptableChildPax": null,
        "RoomCategory": 1,
        "RoomType": 1,
        "Grade": 0,
        "View": 0,
        "Equipment": [
          0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29
        ],
        "Amenity": [
          0,1,2,3,4,5,6,7,8,9,10,11,12
        ],
        "Feature": [],
        "Reason": [],
        "AcceptanceCondition": [],
        "Pictures": [],
        "PlanIds": [1219]
      },
      {
        "RoomId": 1439,
        "RoomName": "部屋3",
        "RoomNameEn": "Test Room 3",
        "RoomNameTw": null,
        "RoomNameCn": null,
        "RoomNameKr": null,
        "RoomDescription": "テスト部屋3です。",
        "RoomDescriptionEn": "Test Room 3",
        "RoomDescriptionTw": null,
        "RoomDescriptionCn": null,
        "RoomDescriptionKr": null,
        "RoomSize": 20,
        "RoomSizeUnit": 0,
        "MinPax": 1,
        "MaxPax": 10,
        "ChildCapacitySetting": null,
        "AcceptableChildPax": null,
        "RoomCategory": 1,
        "RoomType": 1,
        "Grade": 0,
        "View": 0,
        "Equipment": [
          0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29
        ],
        "Amenity": [
          0,1,2,3,4,5,6,7,8,9,10,11,12
        ],
        "Feature": [],
        "Reason": [],
        "AcceptanceCondition": [],
        "Pictures": [],
        "PlanIds": [1219,1220]
      }
    ]
  }
}
```

**Notes:**
- Returns multilingual room names and descriptions (Japanese, English, Chinese, Korean, Taiwanese)
- Provides detailed room specifications including size, capacity, and category
- Includes comprehensive equipment and amenity lists
- Contains plan IDs that can be used to fetch detailed pricing information

---

### 3. Search Available Room Plans
**Route:** POST `/hotels/roomplan/search`  
**Controller Function:** `searchRoomPlan`  
**Middleware:** None  
**Description:** Searches for available rooms and plans based on specific booking conditions including dates, number of guests, and rooms. Returns detailed pricing information including daily rates and discount prices.

**Query Parameters:**
| Parameter | Description | Example |
|-----------|-------------|---------|
| `hotelId` | Unique identifier of the hotel | 23 |

**Input JSON:**
```json
{
  "Conditions": {
    "CheckInDate": "2025-11-29",
    "StayDays": 2,
    "RoomsNum": 1,
    "AdultsNum": 2,
    "ChildrenNum": 0
  }
}
```

**Input Parameters:**
| Parameter | Type | Required | Description |
|-----------|------|----------|-------------|
| `CheckInDate` | String | Yes | Check-in date in YYYY-MM-DD format |
| `StayDays` | Integer | Yes | Number of nights to stay |
| `RoomsNum` | Integer | Yes | Number of rooms required |
| `AdultsNum` | Integer | Yes | Number of adult guests |
| `ChildrenNum` | Integer | Yes | Number of child guests |

**Output JSON (Success):**
```json
{
  "response_code": 200,
  "http_response_status": 200,
  "message": "Room plans search completed",
  "data": {
    "Result": {
      "Status": "OK",
      "Code": 200
    },
    "Rooms": [
      {
        "RoomId": 1437,
        "RoomName": "部屋1",
        "RoomNameEn": "Test Room 1",
        "RoomNameTw": null,
        "RoomNameCn": null,
        "RoomNameKr": null,
        "RoomDescription": "部屋1の詳細です。",
        "RoomDescriptionEn": "Test Room 1",
        "RoomDescriptionTw": null,
        "RoomDescriptionCn": null,
        "RoomDescriptionKr": null,
        "RoomSize": 12,
        "RoomSizeUnit": 0,
        "MinPax": 1,
        "MaxPax": 10,
        "RoomCategory": 1,
        "RoomType": 1,
        "Grade": 0,
        "View": 0,
        "Equipment": [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29],
        "Amenity": [0,1,2,3,4,5,6,7,8,9,10,11,12],
        "Feature": [],
        "Reason": [],
        "AcceptanceCondition": [],
        "Pictures": [],
        "Plans": [
          {
            "PlanId": 1218,
            "PlanName": "プラン1",
            "PlanNameEn": "Test Plan1",
            "PlanNameTw": null,
            "PlanNameCn": null,
            "PlanNameKr": null,
            "Description": "プラン1の詳細です。",
            "DescriptionEn": "Test Plan1",
            "DescriptionTw": null,
            "DescriptionCn": null,
            "DescriptionKr": null,
            "PlanType": 0,
            "Payment": 0,
            "RateType": 0,
            "ReservePeriodStart": "2025-07-23",
            "ReservePeriodEnd": null,
            "CheckinTimeStartH": 15,
            "CheckinTimeStartM": 0,
            "CheckinTimeEndH": 29,
            "CheckinTimeEndM": 0,
            "CheckoutTimeEndH": 10,
            "CheckoutTimeEndM": 0,
            "StayLimitMin": null,
            "StayLimitMax": null,
            "AdvBkCreateStartEnabled": 0,
            "AdvBkCreateStartD": 0,
            "AdvBkCreateStartH": 0,
            "AdvBkCreateStartM": 0,
            "AdvBkCreateEndEnabled": 0,
            "AdvBkCreateEndD": 0,
            "AdvBkCreateEndH": 0,
            "AdvBkCreateEndM": 0,
            "AdvBkModifyEndEnabled": 0,
            "AdvBkModifyEndD": 0,
            "AdvBkModifyEndH": 0,
            "AdvBkModifyEndM": 0,
            "AdvBkCancelEndEnabled": 0,
            "AdvBkCancelEndD": 0,
            "AdvBkCancelEndH": 0,
            "AdvBkCancelEndM": 0,
            "TotalPrice": 48000,
            "AdultPrice": 48000,
            "ChildPrice": 0,
            "AdultUnitPricePerDay": [
              {"Date": "2025-11-29", "Price": 10500},
              {"Date": "2025-11-30", "Price": 13500}
            ],
            "DiscountTotalPrice": 48000,
            "DiscountAdultPrice": 48000,
            "DiscountChildPrice": 0,
            "DiscountAdultUnitPricePerDay": [
              {"Date": "2025-11-29", "Price": 10500},
              {"Date": "2025-11-30", "Price": 13500}
            ],
            "MembershipPlanFlag": 0,
            "OptionalItems": [],
            "Children": {
              "ChildA": {"Acceptable": 0},
              "ChildB": {"Acceptable": 0},
              "ChildC": {"Acceptable": 0},
              "ChildD": {"Acceptable": 0},
              "ChildE": {"Acceptable": 0}
            },
            "CancelPolicy": null,
            "Questions": null,
            "PlanOptions": [],
            "Coupon": [],
            "Pictures": []
          },
          {
            "PlanId": 1220,
            "PlanName": "プラン3",
            "PlanNameEn": "Test Plan 3",
            "PlanNameTw": null,
            "PlanNameCn": null,
            "PlanNameKr": null,
            "Description": "プラン3です。",
            "DescriptionEn": "Test Plan 3",
            "DescriptionTw": null,
            "DescriptionCn": null,
            "DescriptionKr": null,
            "PlanType": 0,
            "Payment": 0,
            "RateType": 1,
            "ReservePeriodStart": "2025-07-23",
            "ReservePeriodEnd": null,
            "CheckinTimeStartH": 0,
            "CheckinTimeStartM": 0,
            "CheckinTimeEndH": 0,
            "CheckinTimeEndM": 0,
            "CheckoutTimeEndH": 0,
            "CheckoutTimeEndM": 0,
            "StayLimitMin": null,
            "StayLimitMax": null,
            "AdvBkCreateStartEnabled": 0,
            "AdvBkCreateStartD": 0,
            "AdvBkCreateStartH": 0,
            "AdvBkCreateStartM": 0,
            "AdvBkCreateEndEnabled": 0,
            "AdvBkCreateEndD": 0,
            "AdvBkCreateEndH": 0,
            "AdvBkCreateEndM": 0,
            "AdvBkModifyEndEnabled": 0,
            "AdvBkModifyEndD": 0,
            "AdvBkModifyEndH": 0,
            "AdvBkModifyEndM": 0,
            "AdvBkCancelEndEnabled": 0,
            "AdvBkCancelEndD": 0,
            "AdvBkCancelEndH": 0,
            "AdvBkCancelEndM": 0,
            "TotalPrice": 47000,
            "DiscountTotalPrice": 47000,
            "MembershipPlanFlag": 0,
            "OptionalItems": [],
            "Children": {
              "ChildA": {"Discount": 0, "Acceptable": 1, "DiscountUnit": 0, "CountAsAdults": 0},
              "ChildB": {"Discount": 0, "Acceptable": 1, "DiscountUnit": 0, "CountAsAdults": 0},
              "ChildC": {"Discount": 0, "Acceptable": 1, "DiscountUnit": 0, "CountAsAdults": 0},
              "ChildD": {"Discount": 0, "Acceptable": 1, "DiscountUnit": 0, "CountAsAdults": 0},
              "ChildE": {"Discount": 0, "Acceptable": 1, "DiscountUnit": 0, "CountAsAdults": 0}
            },
            "CancelPolicy": null,
            "Questions": null,
            "PlanOptions": [],
            "Coupon": [],
            "Pictures": []
          }
        ]
      }
    ]
  }
}
```

**Notes:**
- Returns detailed pricing information including daily breakdowns
- Provides both regular and discounted pricing
- Includes comprehensive child policy information for different age groups
- Contains booking time restrictions and cancellation policies
- Supports multiple rate types and payment options

## Common Response Structure
All API responses follow this standard format:
```json
{
  "response_code": 200,
  "http_response_status": 200,
  "message": "Success message",
  "data": {
    "Result": {
      "Status": "OK",
      "Code": 200
    },
    // ... endpoint-specific data
  }
}
```

## Error Handling
All endpoints return appropriate HTTP status codes and error messages in the response body with the same structure as successful responses.
