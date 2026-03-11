# TWRP Device Tree for Infinix X663 (Infinix NOTE 11)

**Device:** Infinix X663 (Infinix NOTE 11)  
**Chipset:** MediaTek Helio G85 (MT6768)  
**Maintainer:** ALBINsRAJ2025  

---

## Device Specifications

| Feature        | Specification                        |
|----------------|--------------------------------------|
| Chipset        | MediaTek Helio G85 (MT6768)          |
| CPU            | 2x Cortex-A75 @ 2.0GHz + 6x Cortex-A55 @ 1.8GHz |
| GPU            | Mali-G52 MC2                         |
| RAM            | 4/6 GB                               |
| Storage        | 64/128 GB                            |
| Display        | 6.7" IPS LCD, 1080x2400              |
| Battery        | 5000 mAh                             |
| OS (shipped)   | Android 11 (XOS 7.6)                 |

---

## Building TWRP

```bash
# Set up build environment
source build/envsetup.sh
lunch twrp_X663-eng
mka recoveryimage
```

---

## Notes

- This is a **standalone** device tree — no external common tree required.
- Prebuilt kernel and DTB are included in `prebuilt/`.
- bootctrl HAL sources are included in `bootctrl/`.
