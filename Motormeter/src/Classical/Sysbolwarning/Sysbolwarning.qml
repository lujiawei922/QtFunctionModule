import QtQuick 2.0

Item {

    Image {
            id: image0
            x: 327
            y: 667
            width: 45
            height: 45
            visible: true
            source:"qrc:/Image/Common/SysbolWaring/symbol_abs.png"
        }
    Image {
            id: image1
            x: 251
            y: 664
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_acc_active.png"
        }

        Image {
            id: image2
            x: 181
            y: 655
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_acc_warring.png"
        }

        Image {
            id: image3
            x: 102
            y: 626
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_apb.png"
        }

        Image {
            id: image4
            x: 11
            y: 646
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_auto_warning.png"
        }

        Image {
            id: image5
            x: 50
            y: 570
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_b_foglamp.png"
        }

        Image {
            id: image6
            x: 11
            y: 501
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_brakeair.png"
        }

        Image {
            id: image7
            x: 34
            y: 26
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_charge.png"
        }

        Image {
            id: image8
            x: 12
            y: 175
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_cruise_g.png"
        }

        Image {
            id: image9
            x: 58
            y: 110
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_engine_repair.png"
        }

        Image {
            id: image10
            x: 120
            y: 46
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_engine_tru.png"
        }

        Image {
            id: image11
            x: 195
            y: 26
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_abs.png"
        }

        Image {
            id: image12
            x: 268
            y: 11
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_engineoil.png"
        }

        Image {
            id: image13
            x: 343
            y: 11
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_eps.png"
        }

        Image {
            id: image14
            x: 624
            y: 117
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_turn_left.png"
            property bool status: true
            onStatusChanged: {
                if(status){
                    symbol_turn_left.running = true
                }else{
                    symbol_turn_left.running = true
                    image14.visible = true
                }
            }

            Timer{
                id: symbol_turn_left
                interval: 500
                running: true
                repeat: true
                onTriggered: {
                    image14.visible = !image14.visible
                }
            }
        }

        Image {
            id: image15
            x: 1284
            y: 117
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_turn_right.png"
            property bool status: true
            onStatusChanged: {
                if(status){
                    symbol_turn_right.running = true
                }else{
                    symbol_turn_right.running = true
                    image15.visible = true
                }
            }
            Timer{
                id: symbol_turn_right
                interval: 500
                running: true
                repeat: true
                onTriggered: {
                    image15.visible = !image15.visible
                }
            }
        }

        Image {
            id: image16
            x: 1548
            y: 11
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_esc.png"
        }

        Image {
            id: image17
            x: 1621
            y: 11
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_escl.png"
        }

        Image {
            id: image18
            x: 1700
            y: 26
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_escoff.png"
        }

        Image {
            id: image19
            x: 1770
            y: 46
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_f_foglamp.png"
        }

        Image {
            id: image20
            x: 1850
            y: 28
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_highbeam.png"
        }

        Image {
            id: image21
            x: 1826
            y: 111
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_overheat.png"
        }

        Image {
            id: image22
            x: 1865
            y: 176
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_seatbelt.png"
        }

        Image {
            id: image23
            x: 1862
            y: 501
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_seatbelt_2.png"
        }

        Image {
            id: image24
            x: 1814
            y: 570
            width: 46
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_security.png"
        }

        Image {
            id: image25
            x: 1750
            y: 619
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_start_stop.png"
        }

        Image {
            id: image26
            x: 1836
            y: 636
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_start_stop_tru.png"
        }

        Image {
            id: image27
            x: 1682
            y: 646
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_tailonlamp.png"
        }

        Image {
            id: image28
            x: 1614
            y: 661
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_tpms.png"
        }

        Image {
            id: image29
            x: 1547
            y: 661
            width: 45
            height: 45
            visible: true
            source: "qrc:/Image/Common/SysbolWaring/symbol_fuel.png"
        }
}
