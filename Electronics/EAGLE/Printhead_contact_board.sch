<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.3.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="wirepad" urn="urn:adsk.eagle:library:412">
<description>&lt;b&gt;Single Pads&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="SMD1,27-2,54" urn="urn:adsk.eagle:footprint:30822/1" library_version="1">
<description>&lt;b&gt;SMD PAD&lt;/b&gt;</description>
<smd name="1" x="0" y="0" dx="1.27" dy="2.54" layer="1"/>
<text x="0" y="0" size="0.0254" layer="27">&gt;VALUE</text>
<text x="-0.8" y="-2.4" size="1.27" layer="25" rot="R90">&gt;NAME</text>
</package>
</packages>
<packages3d>
<package3d name="SMD1,27-2,54" urn="urn:adsk.eagle:package:30839/1" type="box" library_version="1">
<description>SMD PAD</description>
<packageinstances>
<packageinstance name="SMD1,27-2,54"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="PAD" urn="urn:adsk.eagle:symbol:30808/1" library_version="1">
<wire x1="-1.016" y1="1.016" x2="1.016" y2="-1.016" width="0.254" layer="94"/>
<wire x1="-1.016" y1="-1.016" x2="1.016" y2="1.016" width="0.254" layer="94"/>
<text x="-1.143" y="1.8542" size="1.778" layer="95">&gt;NAME</text>
<text x="-1.143" y="-3.302" size="1.778" layer="96">&gt;VALUE</text>
<pin name="P" x="2.54" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="SMD2" urn="urn:adsk.eagle:component:30857/1" prefix="PAD" uservalue="yes" library_version="1">
<description>&lt;b&gt;SMD PAD&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="PAD" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SMD1,27-2,54">
<connects>
<connect gate="1" pin="P" pad="1"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:30839/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-molex" urn="urn:adsk.eagle:library:165">
<description>&lt;b&gt;Molex Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="53047-13" library_version="2">
<description>&lt;b&gt;1.25mm Pitch PicoBlade™ Wire-to-Board Header, Vertical, with Friction Lock, 13 Circuits&lt;/b&gt;&lt;p&gt;&lt;a href =http://www.molex.com/pdm_docs/sd/530471310_sd.pdf&gt;Datasheet &lt;/a&gt;</description>
<wire x1="-8.9" y1="-1.5" x2="8.9" y2="-1.5" width="0.2032" layer="21"/>
<wire x1="8.9" y1="-1.5" x2="8.9" y2="1.5" width="0.2032" layer="21"/>
<wire x1="8.9" y1="1.5" x2="-8.9" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-8.9" y1="1.5" x2="-8.9" y2="-1.5" width="0.2032" layer="21"/>
<wire x1="-8.875" y1="-0.25" x2="-8.5" y2="-0.25" width="0.0508" layer="21"/>
<wire x1="-8.5" y1="-0.25" x2="-8.5" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="8.5" y1="-0.25" x2="8.875" y2="-0.25" width="0.0508" layer="21"/>
<wire x1="8.5" y1="-0.25" x2="8.5" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-8.875" y1="0.375" x2="-8.5" y2="0.375" width="0.0508" layer="21"/>
<wire x1="8.5" y1="0.375" x2="8.875" y2="0.375" width="0.0508" layer="21"/>
<wire x1="-8.5" y1="0.375" x2="-8.5" y2="1.125" width="0.0508" layer="21"/>
<wire x1="-8.5" y1="1.125" x2="8.5" y2="1.125" width="0.0508" layer="21"/>
<wire x1="8.5" y1="1.125" x2="8.5" y2="0.375" width="0.0508" layer="21"/>
<wire x1="8.5" y1="1.125" x2="8.75" y2="1.375" width="0.0508" layer="21"/>
<wire x1="-8.5" y1="1.125" x2="-8.75" y2="1.375" width="0.0508" layer="21"/>
<pad name="1" x="7.5" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="2" x="6.25" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="3" x="5" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="4" x="3.75" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="5" x="2.5" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="6" x="1.25" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="7" x="0" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="8" x="-1.25" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="9" x="-2.5" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="10" x="-3.75" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="11" x="-5" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="12" x="-6.25" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="13" x="-7.5" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<text x="-8.75" y="1.75" size="1.27" layer="25">&gt;NAME</text>
<text x="-2" y="1.75" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-8.875" y1="-1.5" x2="8.875" y2="-1.125" layer="21"/>
</package>
<package name="53048-13" library_version="2">
<description>&lt;b&gt;1.25mm Pitch PicoBlade™ Header, Right Angle, 13 Circuits&lt;/b&gt;&lt;p&gt;&lt;a href =http://www.molex.com/pdm_docs/sd/530481310_sd.pdf&gt;Datasheet &lt;/a&gt;</description>
<wire x1="-8.9" y1="-2.25" x2="-8.375" y2="-2.25" width="0.2032" layer="21"/>
<wire x1="8.375" y1="-2.25" x2="8.9" y2="-2.25" width="0.2032" layer="21"/>
<wire x1="8.9" y1="-2.25" x2="8.9" y2="3.125" width="0.2032" layer="21"/>
<wire x1="8.9" y1="3.125" x2="8.75" y2="3.125" width="0.2032" layer="21"/>
<wire x1="8.75" y1="3.125" x2="-8.75" y2="3.125" width="0.2032" layer="21"/>
<wire x1="-8.75" y1="3.125" x2="-8.9" y2="3.125" width="0.2032" layer="21"/>
<wire x1="-8.9" y1="3.125" x2="-8.9" y2="-2.25" width="0.2032" layer="21"/>
<wire x1="-8.875" y1="1.5" x2="-8.375" y2="1.5" width="0.0508" layer="21"/>
<wire x1="-8.375" y1="1.5" x2="-8.125" y2="1.5" width="0.0508" layer="21"/>
<wire x1="-8.125" y1="1.5" x2="-8.125" y2="0.625" width="0.0508" layer="21"/>
<wire x1="-8.125" y1="0.625" x2="8.125" y2="0.625" width="0.0508" layer="21"/>
<wire x1="8.125" y1="1.5" x2="8.375" y2="1.5" width="0.0508" layer="21"/>
<wire x1="8.375" y1="1.5" x2="8.875" y2="1.5" width="0.0508" layer="21"/>
<wire x1="8.125" y1="1.5" x2="8.125" y2="0.625" width="0.0508" layer="21"/>
<wire x1="-8.375" y1="-1" x2="8.375" y2="-1" width="0.2032" layer="51"/>
<wire x1="-7.75" y1="-1.5" x2="-7.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-6.5" y1="-1.5" x2="-6.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-6.625" y1="-1.625" x2="-7.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-7.25" y1="-1.5" x2="-7.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-5.25" y1="-1.5" x2="-5.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-5.375" y1="-1.625" x2="-5.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-6" y1="-1.5" x2="-5.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-4" y1="-1.5" x2="-4.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-4.125" y1="-1.625" x2="-4.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-4.75" y1="-1.5" x2="-4.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-2.75" y1="-1.5" x2="-2.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-2.875" y1="-1.625" x2="-3.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-3.5" y1="-1.5" x2="-3.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-1.5" y1="-1.5" x2="-1.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-1.625" y1="-1.625" x2="-2.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-2.25" y1="-1.5" x2="-2.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-0.25" y1="-1.5" x2="-0.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-0.375" y1="-1.625" x2="-0.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-1" y1="-1.5" x2="-0.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="1" y1="-1.5" x2="0.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="0.875" y1="-1.625" x2="0.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="0.25" y1="-1.5" x2="0.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="2.25" y1="-1.5" x2="2.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="2.125" y1="-1.625" x2="1.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="1.5" y1="-1.5" x2="1.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="3.5" y1="-1.5" x2="3.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="3.375" y1="-1.625" x2="2.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="2.75" y1="-1.5" x2="2.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="4.75" y1="-1.5" x2="4.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="4.625" y1="-1.625" x2="4.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="4" y1="-1.5" x2="4.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="6" y1="-1.5" x2="5.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="5.875" y1="-1.625" x2="5.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="5.25" y1="-1.5" x2="5.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="7.25" y1="-1.5" x2="7.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="7.125" y1="-1.625" x2="6.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="6.5" y1="-1.5" x2="6.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="8.375" y1="-1.625" x2="7.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="7.75" y1="-1.5" x2="7.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-7.875" y1="-1.625" x2="-8.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-8.875" y1="-1" x2="-8.375" y2="-1" width="0.2032" layer="21"/>
<wire x1="-8.375" y1="-1" x2="-8.375" y2="-2.25" width="0.2032" layer="21"/>
<wire x1="8.375" y1="-1" x2="8.875" y2="-1" width="0.2032" layer="21"/>
<wire x1="8.375" y1="-1" x2="8.375" y2="-2.25" width="0.2032" layer="21"/>
<wire x1="-8.375" y1="1.5" x2="-8.375" y2="2.75" width="0.0508" layer="21"/>
<wire x1="-8.375" y1="2.75" x2="8.375" y2="2.75" width="0.0508" layer="21"/>
<wire x1="8.375" y1="2.75" x2="8.375" y2="1.5" width="0.0508" layer="21"/>
<wire x1="-8.375" y1="2.75" x2="-8.75" y2="3.125" width="0.0508" layer="21"/>
<wire x1="8.375" y1="2.75" x2="8.75" y2="3.125" width="0.0508" layer="21"/>
<wire x1="-7.625" y1="1.5" x2="-7.5" y2="2" width="0.2032" layer="21"/>
<wire x1="-7.5" y1="2" x2="-7.375" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-6.375" y1="1.5" x2="-6.25" y2="2" width="0.2032" layer="21"/>
<wire x1="-6.25" y1="2" x2="-6.125" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-5.125" y1="1.5" x2="-5" y2="2" width="0.2032" layer="21"/>
<wire x1="-5" y1="2" x2="-4.875" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-3.875" y1="1.5" x2="-3.75" y2="2" width="0.2032" layer="21"/>
<wire x1="-3.75" y1="2" x2="-3.625" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-2.625" y1="1.5" x2="-2.5" y2="2" width="0.2032" layer="21"/>
<wire x1="-2.5" y1="2" x2="-2.375" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-1.375" y1="1.5" x2="-1.25" y2="2" width="0.2032" layer="21"/>
<wire x1="-1.25" y1="2" x2="-1.125" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-0.125" y1="1.5" x2="0" y2="2" width="0.2032" layer="21"/>
<wire x1="0" y1="2" x2="0.125" y2="1.5" width="0.2032" layer="21"/>
<wire x1="1.125" y1="1.5" x2="1.25" y2="2" width="0.2032" layer="21"/>
<wire x1="1.25" y1="2" x2="1.375" y2="1.5" width="0.2032" layer="21"/>
<wire x1="2.375" y1="1.5" x2="2.5" y2="2" width="0.2032" layer="21"/>
<wire x1="2.5" y1="2" x2="2.625" y2="1.5" width="0.2032" layer="21"/>
<wire x1="3.625" y1="1.5" x2="3.75" y2="2" width="0.2032" layer="21"/>
<wire x1="3.75" y1="2" x2="3.875" y2="1.5" width="0.2032" layer="21"/>
<wire x1="4.875" y1="1.5" x2="5" y2="2" width="0.2032" layer="21"/>
<wire x1="5" y1="2" x2="5.125" y2="1.5" width="0.2032" layer="21"/>
<wire x1="6.125" y1="1.5" x2="6.25" y2="2" width="0.2032" layer="21"/>
<wire x1="6.25" y1="2" x2="6.375" y2="1.5" width="0.2032" layer="21"/>
<wire x1="7.375" y1="1.5" x2="7.5" y2="2" width="0.2032" layer="21"/>
<wire x1="7.5" y1="2" x2="7.625" y2="1.5" width="0.2032" layer="21"/>
<pad name="1" x="7.5" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="2" x="6.25" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="3" x="5" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="4" x="3.75" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="5" x="2.5" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="6" x="1.25" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="7" x="0" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="8" x="-1.25" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="9" x="-2.5" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="10" x="-3.75" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="11" x="-5" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="12" x="-6.25" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="13" x="-7.5" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<text x="-7.5" y="3.375" size="1.27" layer="25">&gt;NAME</text>
<text x="-8.125" y="-3.625" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-7.75" y1="-1.5" x2="-7.25" y2="-1" layer="51"/>
<rectangle x1="-6.5" y1="-1.5" x2="-6" y2="-1" layer="51"/>
<rectangle x1="-5.25" y1="-1.5" x2="-4.75" y2="-1" layer="51"/>
<rectangle x1="-4" y1="-1.5" x2="-3.5" y2="-1" layer="51"/>
<rectangle x1="-2.75" y1="-1.5" x2="-2.25" y2="-1" layer="51"/>
<rectangle x1="-1.5" y1="-1.5" x2="-1" y2="-1" layer="51"/>
<rectangle x1="-0.25" y1="-1.5" x2="0.25" y2="-1" layer="51"/>
<rectangle x1="1" y1="-1.5" x2="1.5" y2="-1" layer="51"/>
<rectangle x1="2.25" y1="-1.5" x2="2.75" y2="-1" layer="51"/>
<rectangle x1="3.5" y1="-1.5" x2="4" y2="-1" layer="51"/>
<rectangle x1="4.75" y1="-1.5" x2="5.25" y2="-1" layer="51"/>
<rectangle x1="6" y1="-1.5" x2="6.5" y2="-1" layer="51"/>
<rectangle x1="7.25" y1="-1.5" x2="7.75" y2="-1" layer="51"/>
<rectangle x1="-7.75" y1="0.625" x2="-7.25" y2="1.5" layer="21"/>
<rectangle x1="-6.5" y1="0.625" x2="-6" y2="1.5" layer="21"/>
<rectangle x1="-5.25" y1="0.625" x2="-4.75" y2="1.5" layer="21"/>
<rectangle x1="-4" y1="0.625" x2="-3.5" y2="1.5" layer="21"/>
<rectangle x1="-2.75" y1="0.625" x2="-2.25" y2="1.5" layer="21"/>
<rectangle x1="-1.5" y1="0.625" x2="-1" y2="1.5" layer="21"/>
<rectangle x1="-0.25" y1="0.625" x2="0.25" y2="1.5" layer="21"/>
<rectangle x1="1" y1="0.625" x2="1.5" y2="1.5" layer="21"/>
<rectangle x1="2.25" y1="0.625" x2="2.75" y2="1.5" layer="21"/>
<rectangle x1="3.5" y1="0.625" x2="4" y2="1.5" layer="21"/>
<rectangle x1="4.75" y1="0.625" x2="5.25" y2="1.5" layer="21"/>
<rectangle x1="6" y1="0.625" x2="6.5" y2="1.5" layer="21"/>
<rectangle x1="7.25" y1="0.625" x2="7.75" y2="1.5" layer="21"/>
</package>
<package name="53261-13" library_version="2">
<description>&lt;b&gt;1.25mm Pitch PicoBlade™ Header, Surface Mount, Right Angle, 13 Circuits&lt;/b&gt;&lt;p&gt;&lt;a href =http://www.molex.com/pdm_docs/sd/532611371_sd.pdf&gt;Datasheet &lt;/a&gt;</description>
<wire x1="-8.9" y1="-1.375" x2="-8.375" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="-8.375" y1="-1.375" x2="8.375" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="8.375" y1="-1.375" x2="8.9" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="8.9" y1="-1.375" x2="8.9" y2="2.625" width="0.2032" layer="21"/>
<wire x1="8.9" y1="2.625" x2="8.75" y2="2.625" width="0.2032" layer="21"/>
<wire x1="8.75" y1="2.625" x2="-8.75" y2="2.625" width="0.2032" layer="21"/>
<wire x1="-8.75" y1="2.625" x2="-8.9" y2="2.625" width="0.2032" layer="21"/>
<wire x1="-8.9" y1="2.625" x2="-8.9" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="-8.875" y1="1.625" x2="-8.375" y2="1.625" width="0.0508" layer="21"/>
<wire x1="-8.375" y1="1.625" x2="-8.125" y2="1.625" width="0.0508" layer="21"/>
<wire x1="-8.125" y1="1.625" x2="-8.125" y2="1" width="0.0508" layer="21"/>
<wire x1="-8.125" y1="1" x2="8.125" y2="1" width="0.0508" layer="21"/>
<wire x1="8.125" y1="1.625" x2="8.375" y2="1.625" width="0.0508" layer="21"/>
<wire x1="8.375" y1="1.625" x2="8.875" y2="1.625" width="0.0508" layer="21"/>
<wire x1="8.125" y1="1.625" x2="8.125" y2="1" width="0.0508" layer="21"/>
<wire x1="-8.875" y1="-0.75" x2="-8.375" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-8.375" y1="-0.75" x2="-8.375" y2="-1.375" width="0.0508" layer="21"/>
<wire x1="8.375" y1="-0.75" x2="8.875" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="8.375" y1="-0.75" x2="8.375" y2="-1.375" width="0.0508" layer="21"/>
<wire x1="-8.375" y1="1.625" x2="-8.375" y2="2.25" width="0.0508" layer="21"/>
<wire x1="-8.375" y1="2.25" x2="8.375" y2="2.25" width="0.0508" layer="21"/>
<wire x1="8.375" y1="2.25" x2="8.375" y2="1.625" width="0.0508" layer="21"/>
<wire x1="-8.375" y1="2.25" x2="-8.75" y2="2.625" width="0.0508" layer="21"/>
<wire x1="8.375" y1="2.25" x2="8.75" y2="2.625" width="0.0508" layer="21"/>
<wire x1="-7.75" y1="-1.25" x2="-7.75" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-7.75" y1="-0.75" x2="-7.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-7.25" y1="-0.75" x2="-7.25" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-6.5" y1="-1.25" x2="-6.5" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-6.5" y1="-0.75" x2="-6" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-6" y1="-0.75" x2="-6" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-5.25" y1="-1.25" x2="-5.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-5.25" y1="-0.75" x2="-4.75" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-4.75" y1="-0.75" x2="-4.75" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-4" y1="-1.25" x2="-4" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-4" y1="-0.75" x2="-3.5" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-3.5" y1="-0.75" x2="-3.5" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-2.75" y1="-1.25" x2="-2.75" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-2.75" y1="-0.75" x2="-2.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-2.25" y1="-0.75" x2="-2.25" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-1.5" y1="-1.25" x2="-1.5" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-1.5" y1="-0.75" x2="-1" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-1" y1="-0.75" x2="-1" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-0.25" y1="-1.25" x2="-0.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-0.25" y1="-0.75" x2="0.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="0.25" y1="-0.75" x2="0.25" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="1" y1="-1.25" x2="1" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="1" y1="-0.75" x2="1.5" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="1.5" y1="-0.75" x2="1.5" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="2.25" y1="-1.25" x2="2.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="2.25" y1="-0.75" x2="2.75" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="2.75" y1="-0.75" x2="2.75" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="3.5" y1="-1.25" x2="3.5" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="3.5" y1="-0.75" x2="4" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="4" y1="-0.75" x2="4" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="4.75" y1="-1.25" x2="4.75" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="4.75" y1="-0.75" x2="5.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="5.25" y1="-0.75" x2="5.25" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="6" y1="-1.25" x2="6" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="6" y1="-0.75" x2="6.5" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="6.5" y1="-0.75" x2="6.5" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="7.25" y1="-1.25" x2="7.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="7.25" y1="-0.75" x2="7.75" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="7.75" y1="-0.75" x2="7.75" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-9" y1="2.25" x2="-10.875" y2="2.25" width="0.2032" layer="51"/>
<wire x1="-10.875" y1="2.25" x2="-10.875" y2="-0.75" width="0.2032" layer="51"/>
<wire x1="-10.875" y1="-0.75" x2="-9" y2="-0.75" width="0.2032" layer="51"/>
<wire x1="9" y1="-0.75" x2="10.875" y2="-0.75" width="0.2032" layer="51"/>
<wire x1="10.875" y1="-0.75" x2="10.875" y2="2.25" width="0.2032" layer="51"/>
<wire x1="10.875" y1="2.25" x2="9" y2="2.25" width="0.2032" layer="51"/>
<smd name="1" x="7.5" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="2" x="6.25" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="3" x="5" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="4" x="3.75" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="5" x="2.5" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="6" x="1.25" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="7" x="0" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="8" x="-1.25" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="9" x="-2.5" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="10" x="-3.75" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="11" x="-5" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="12" x="-6.25" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="13" x="-7.5" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="S1" x="10" y="0.625" dx="2.1" dy="3" layer="1"/>
<smd name="S2" x="-10" y="0.625" dx="2.1" dy="3" layer="1"/>
<text x="-7.5" y="2.875" size="1.27" layer="25">&gt;NAME</text>
<text x="-6.375" y="-0.5" size="1.27" layer="27">&gt;VALUE</text>
<text x="9.5" y="-0.25" size="1.9304" layer="51">1</text>
<rectangle x1="-7.75" y1="1" x2="-7.25" y2="1.875" layer="21"/>
<rectangle x1="-6.5" y1="1" x2="-6" y2="1.875" layer="21"/>
<rectangle x1="-5.25" y1="1" x2="-4.75" y2="1.875" layer="21"/>
<rectangle x1="-4" y1="1" x2="-3.5" y2="1.875" layer="21"/>
<rectangle x1="-2.75" y1="1" x2="-2.25" y2="1.875" layer="21"/>
<rectangle x1="-1.5" y1="1" x2="-1" y2="1.875" layer="21"/>
<rectangle x1="-0.25" y1="1" x2="0.25" y2="1.875" layer="21"/>
<rectangle x1="1" y1="1" x2="1.5" y2="1.875" layer="21"/>
<rectangle x1="2.25" y1="1" x2="2.75" y2="1.875" layer="21"/>
<rectangle x1="3.5" y1="1" x2="4" y2="1.875" layer="21"/>
<rectangle x1="4.75" y1="1" x2="5.25" y2="1.875" layer="21"/>
<rectangle x1="6" y1="1" x2="6.5" y2="1.875" layer="21"/>
<rectangle x1="7.25" y1="1" x2="7.75" y2="1.875" layer="21"/>
</package>
<package name="53398-13" library_version="2">
<description>&lt;b&gt;1.25mm Pitch PicoBlade™ Header, Surface Mount, Vertical, 13 Circuits&lt;/b&gt;&lt;p&gt;&lt;a href =http://www.molex.com/pdm_docs/sd/533981371_sd.pdf&gt;Datasheet &lt;/a&gt;</description>
<wire x1="-8.9" y1="-1.375" x2="-8.125" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="-8.125" y1="-1.375" x2="8.125" y2="-1.375" width="0.0508" layer="21"/>
<wire x1="8.125" y1="-1.375" x2="8.9" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="8.9" y1="-1.375" x2="8.9" y2="2.125" width="0.2032" layer="21"/>
<wire x1="8.9" y1="2.125" x2="8.75" y2="2.125" width="0.2032" layer="21"/>
<wire x1="8.75" y1="2.125" x2="-8.75" y2="2.125" width="0.2032" layer="21"/>
<wire x1="-8.75" y1="2.125" x2="-8.9" y2="2.125" width="0.2032" layer="21"/>
<wire x1="-8.9" y1="2.125" x2="-8.9" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="-8.875" y1="1" x2="-8.375" y2="1" width="0.0508" layer="21"/>
<wire x1="8.375" y1="1" x2="8.875" y2="1" width="0.0508" layer="21"/>
<wire x1="-8.875" y1="-0.25" x2="-8.375" y2="-0.25" width="0.0508" layer="21"/>
<wire x1="-8.375" y1="-0.25" x2="-8.375" y2="-1" width="0.0508" layer="21"/>
<wire x1="8.375" y1="-0.25" x2="8.875" y2="-0.25" width="0.0508" layer="21"/>
<wire x1="8.375" y1="-0.25" x2="8.375" y2="-1" width="0.0508" layer="21"/>
<wire x1="-8.375" y1="1" x2="-8.375" y2="1.75" width="0.0508" layer="21"/>
<wire x1="-8.375" y1="1.75" x2="8.375" y2="1.75" width="0.0508" layer="21"/>
<wire x1="8.375" y1="1.75" x2="8.375" y2="1" width="0.0508" layer="21"/>
<wire x1="-8.375" y1="1.75" x2="-8.75" y2="2.125" width="0.0508" layer="21"/>
<wire x1="8.375" y1="1.75" x2="8.75" y2="2.125" width="0.0508" layer="21"/>
<wire x1="-9" y1="2.125" x2="-10.875" y2="2.125" width="0.2032" layer="51"/>
<wire x1="-10.875" y1="2.125" x2="-10.875" y2="-0.75" width="0.2032" layer="51"/>
<wire x1="-10.875" y1="-0.75" x2="-9" y2="-0.75" width="0.2032" layer="51"/>
<wire x1="9" y1="-0.75" x2="10.875" y2="-0.75" width="0.2032" layer="51"/>
<wire x1="10.875" y1="-0.75" x2="10.875" y2="2.125" width="0.2032" layer="51"/>
<wire x1="10.875" y1="2.125" x2="9" y2="2.125" width="0.2032" layer="51"/>
<wire x1="-8.875" y1="-1" x2="-8.375" y2="-1" width="0.0508" layer="21"/>
<wire x1="-8.375" y1="-1" x2="-8.125" y2="-1" width="0.0508" layer="21"/>
<wire x1="-8.125" y1="-1" x2="-8.125" y2="-1.375" width="0.0508" layer="21"/>
<wire x1="8.375" y1="-1" x2="8.875" y2="-1" width="0.0508" layer="21"/>
<wire x1="8.125" y1="-1" x2="8.375" y2="-1" width="0.0508" layer="21"/>
<wire x1="8.125" y1="-1" x2="8.125" y2="-1.375" width="0.0508" layer="21"/>
<smd name="1" x="7.5" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="2" x="6.25" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="3" x="5" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="4" x="3.75" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="5" x="2.5" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="6" x="1.25" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="7" x="0" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="8" x="-1.25" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="9" x="-2.5" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="10" x="-3.75" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="11" x="-5" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="12" x="-6.25" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="13" x="-7.5" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="S1" x="10" y="0.625" dx="2.1" dy="3" layer="1"/>
<smd name="S2" x="-10" y="0.625" dx="2.1" dy="3" layer="1"/>
<text x="-8.625" y="2.375" size="1.27" layer="25">&gt;NAME</text>
<text x="-8.125" y="-1" size="1.27" layer="27">&gt;VALUE</text>
<text x="9.375" y="-0.25" size="1.9304" layer="51">1</text>
<rectangle x1="-7.75" y1="0.375" x2="-7.25" y2="1" layer="21"/>
<rectangle x1="-6.5" y1="0.375" x2="-6" y2="1" layer="21"/>
<rectangle x1="-5.25" y1="0.375" x2="-4.75" y2="1" layer="21"/>
<rectangle x1="-4" y1="0.375" x2="-3.5" y2="1" layer="21"/>
<rectangle x1="-2.75" y1="0.375" x2="-2.25" y2="1" layer="21"/>
<rectangle x1="-1.5" y1="0.375" x2="-1" y2="1" layer="21"/>
<rectangle x1="-0.25" y1="0.375" x2="0.25" y2="1" layer="21"/>
<rectangle x1="1" y1="0.375" x2="1.5" y2="1" layer="21"/>
<rectangle x1="2.25" y1="0.375" x2="2.75" y2="1" layer="21"/>
<rectangle x1="3.5" y1="0.375" x2="4" y2="1" layer="21"/>
<rectangle x1="4.75" y1="0.375" x2="5.25" y2="1" layer="21"/>
<rectangle x1="6" y1="0.375" x2="6.5" y2="1" layer="21"/>
<rectangle x1="7.25" y1="0.375" x2="7.75" y2="1" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="MV" library_version="2">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<text x="-0.762" y="1.397" size="1.778" layer="96">&gt;VALUE</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
<symbol name="M" library_version="2">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="53?-13" prefix="X" library_version="2">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;&lt;p&gt;
wire to board 1.25 mm (.049 inch) pitch header</description>
<gates>
<gate name="-1" symbol="MV" x="0" y="15.24" addlevel="always" swaplevel="1"/>
<gate name="-2" symbol="M" x="0" y="12.7" addlevel="always" swaplevel="1"/>
<gate name="-3" symbol="M" x="0" y="10.16" addlevel="always" swaplevel="1"/>
<gate name="-4" symbol="M" x="0" y="7.62" addlevel="always" swaplevel="1"/>
<gate name="-5" symbol="M" x="0" y="5.08" addlevel="always" swaplevel="1"/>
<gate name="-6" symbol="M" x="0" y="2.54" addlevel="always" swaplevel="1"/>
<gate name="-7" symbol="M" x="0" y="0" addlevel="always" swaplevel="1"/>
<gate name="-8" symbol="M" x="0" y="-2.54" addlevel="always" swaplevel="1"/>
<gate name="-9" symbol="M" x="0" y="-5.08" addlevel="always" swaplevel="1"/>
<gate name="-10" symbol="M" x="0" y="-7.62" addlevel="always" swaplevel="1"/>
<gate name="-11" symbol="M" x="0" y="-10.16" addlevel="always" swaplevel="1"/>
<gate name="-12" symbol="M" x="0" y="-12.7" addlevel="always" swaplevel="1"/>
<gate name="-13" symbol="M" x="0" y="-15.24" addlevel="always" swaplevel="1"/>
</gates>
<devices>
<device name="047" package="53047-13">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-10" pin="S" pad="10"/>
<connect gate="-11" pin="S" pad="11"/>
<connect gate="-12" pin="S" pad="12"/>
<connect gate="-13" pin="S" pad="13"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
<connect gate="-5" pin="S" pad="5"/>
<connect gate="-6" pin="S" pad="6"/>
<connect gate="-7" pin="S" pad="7"/>
<connect gate="-8" pin="S" pad="8"/>
<connect gate="-9" pin="S" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="MOLEX" constant="no"/>
<attribute name="MPN" value="53047-1310-C" constant="no"/>
<attribute name="OC_FARNELL" value="1012238" constant="no"/>
<attribute name="OC_NEWARK" value="03N7646" constant="no"/>
</technology>
</technologies>
</device>
<device name="048" package="53048-13">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-10" pin="S" pad="10"/>
<connect gate="-11" pin="S" pad="11"/>
<connect gate="-12" pin="S" pad="12"/>
<connect gate="-13" pin="S" pad="13"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
<connect gate="-5" pin="S" pad="5"/>
<connect gate="-6" pin="S" pad="6"/>
<connect gate="-7" pin="S" pad="7"/>
<connect gate="-8" pin="S" pad="8"/>
<connect gate="-9" pin="S" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="MOLEX" constant="no"/>
<attribute name="MPN" value="53048-1310-C" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="03N7647" constant="no"/>
</technology>
</technologies>
</device>
<device name="261" package="53261-13">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-10" pin="S" pad="10"/>
<connect gate="-11" pin="S" pad="11"/>
<connect gate="-12" pin="S" pad="12"/>
<connect gate="-13" pin="S" pad="13"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
<connect gate="-5" pin="S" pad="5"/>
<connect gate="-6" pin="S" pad="6"/>
<connect gate="-7" pin="S" pad="7"/>
<connect gate="-8" pin="S" pad="8"/>
<connect gate="-9" pin="S" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="MOLEX" constant="no"/>
<attribute name="MPN" value="53261-1371" constant="no"/>
<attribute name="OC_FARNELL" value="1756927" constant="no"/>
<attribute name="OC_NEWARK" value="92M6827" constant="no"/>
</technology>
</technologies>
</device>
<device name="398" package="53398-13">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-10" pin="S" pad="10"/>
<connect gate="-11" pin="S" pad="11"/>
<connect gate="-12" pin="S" pad="12"/>
<connect gate="-13" pin="S" pad="13"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
<connect gate="-5" pin="S" pad="5"/>
<connect gate="-6" pin="S" pad="6"/>
<connect gate="-7" pin="S" pad="7"/>
<connect gate="-8" pin="S" pad="8"/>
<connect gate="-9" pin="S" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="MOLEX" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0.01" drill="0">
<clearance class="0" value="0.205"/>
</class>
</classes>
<parts>
<part name="IN" library="con-molex" library_urn="urn:adsk.eagle:library:165" deviceset="53?-13" device="047"/>
<part name="CMN" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="SMD2" device="" package3d_urn="urn:adsk.eagle:package:30839/1"/>
<part name="1" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="SMD2" device="" package3d_urn="urn:adsk.eagle:package:30839/1"/>
<part name="2" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="SMD2" device="" package3d_urn="urn:adsk.eagle:package:30839/1"/>
<part name="3" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="SMD2" device="" package3d_urn="urn:adsk.eagle:package:30839/1"/>
<part name="4" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="SMD2" device="" package3d_urn="urn:adsk.eagle:package:30839/1"/>
<part name="5" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="SMD2" device="" package3d_urn="urn:adsk.eagle:package:30839/1"/>
<part name="6" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="SMD2" device="" package3d_urn="urn:adsk.eagle:package:30839/1"/>
<part name="7" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="SMD2" device="" package3d_urn="urn:adsk.eagle:package:30839/1"/>
<part name="8" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="SMD2" device="" package3d_urn="urn:adsk.eagle:package:30839/1"/>
<part name="9" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="SMD2" device="" package3d_urn="urn:adsk.eagle:package:30839/1"/>
<part name="10" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="SMD2" device="" package3d_urn="urn:adsk.eagle:package:30839/1"/>
<part name="11" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="SMD2" device="" package3d_urn="urn:adsk.eagle:package:30839/1"/>
<part name="12" library="wirepad" library_urn="urn:adsk.eagle:library:412" deviceset="SMD2" device="" package3d_urn="urn:adsk.eagle:package:30839/1"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="IN" gate="-1" x="20.32" y="76.2" smashed="yes" rot="MR0">
<attribute name="NAME" x="17.78" y="75.438" size="1.524" layer="95" rot="MR0"/>
<attribute name="VALUE" x="21.082" y="77.597" size="1.778" layer="96" rot="MR0"/>
</instance>
<instance part="IN" gate="-2" x="20.32" y="66.04" smashed="yes" rot="MR0">
<attribute name="NAME" x="17.78" y="65.278" size="1.524" layer="95" rot="MR0"/>
</instance>
<instance part="IN" gate="-3" x="20.32" y="55.88" smashed="yes" rot="MR0">
<attribute name="NAME" x="17.78" y="55.118" size="1.524" layer="95" rot="MR0"/>
</instance>
<instance part="IN" gate="-4" x="20.32" y="45.72" smashed="yes" rot="MR0">
<attribute name="NAME" x="17.78" y="44.958" size="1.524" layer="95" rot="MR0"/>
</instance>
<instance part="IN" gate="-5" x="20.32" y="35.56" smashed="yes" rot="MR0">
<attribute name="NAME" x="17.78" y="34.798" size="1.524" layer="95" rot="MR0"/>
</instance>
<instance part="IN" gate="-6" x="20.32" y="25.4" smashed="yes" rot="MR0">
<attribute name="NAME" x="17.78" y="24.638" size="1.524" layer="95" rot="MR0"/>
</instance>
<instance part="IN" gate="-7" x="20.32" y="15.24" smashed="yes" rot="MR0">
<attribute name="NAME" x="17.78" y="14.478" size="1.524" layer="95" rot="MR0"/>
</instance>
<instance part="IN" gate="-8" x="20.32" y="5.08" smashed="yes" rot="MR0">
<attribute name="NAME" x="17.78" y="4.318" size="1.524" layer="95" rot="MR0"/>
</instance>
<instance part="IN" gate="-9" x="20.32" y="-5.08" smashed="yes" rot="MR0">
<attribute name="NAME" x="17.78" y="-5.842" size="1.524" layer="95" rot="MR0"/>
</instance>
<instance part="IN" gate="-10" x="20.32" y="-15.24" smashed="yes" rot="MR0">
<attribute name="NAME" x="17.78" y="-16.002" size="1.524" layer="95" rot="MR0"/>
</instance>
<instance part="IN" gate="-11" x="20.32" y="-25.4" smashed="yes" rot="MR0">
<attribute name="NAME" x="17.78" y="-26.162" size="1.524" layer="95" rot="MR0"/>
</instance>
<instance part="IN" gate="-12" x="20.32" y="-35.56" smashed="yes" rot="MR0">
<attribute name="NAME" x="17.78" y="-36.322" size="1.524" layer="95" rot="MR0"/>
</instance>
<instance part="IN" gate="-13" x="20.32" y="-45.72" smashed="yes" rot="MR0">
<attribute name="NAME" x="17.78" y="-46.482" size="1.524" layer="95" rot="MR0"/>
</instance>
<instance part="CMN" gate="1" x="63.5" y="76.2" smashed="yes" rot="R180">
<attribute name="NAME" x="64.643" y="74.3458" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="64.643" y="79.502" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="1" gate="1" x="63.5" y="66.04" smashed="yes" rot="R180">
<attribute name="NAME" x="64.643" y="64.1858" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="64.643" y="69.342" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="2" gate="1" x="63.5" y="55.88" smashed="yes" rot="R180">
<attribute name="NAME" x="64.643" y="54.0258" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="64.643" y="59.182" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="3" gate="1" x="63.5" y="45.72" smashed="yes" rot="R180">
<attribute name="NAME" x="64.643" y="43.8658" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="64.643" y="49.022" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="4" gate="1" x="63.5" y="35.56" smashed="yes" rot="R180">
<attribute name="NAME" x="64.643" y="33.7058" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="64.643" y="38.862" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="5" gate="1" x="63.5" y="25.4" smashed="yes" rot="R180">
<attribute name="NAME" x="64.643" y="23.5458" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="64.643" y="28.702" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="6" gate="1" x="63.5" y="15.24" smashed="yes" rot="R180">
<attribute name="NAME" x="64.643" y="13.3858" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="64.643" y="18.542" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="7" gate="1" x="63.5" y="5.08" smashed="yes" rot="R180">
<attribute name="NAME" x="64.643" y="3.2258" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="64.643" y="8.382" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="8" gate="1" x="63.5" y="-5.08" smashed="yes" rot="R180">
<attribute name="NAME" x="64.643" y="-6.9342" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="64.643" y="-1.778" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="9" gate="1" x="63.5" y="-15.24" smashed="yes" rot="R180">
<attribute name="NAME" x="64.643" y="-17.0942" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="64.643" y="-11.938" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="10" gate="1" x="63.5" y="-25.4" smashed="yes" rot="R180">
<attribute name="NAME" x="64.643" y="-27.2542" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="64.643" y="-22.098" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="11" gate="1" x="63.5" y="-35.56" smashed="yes" rot="R180">
<attribute name="NAME" x="64.643" y="-37.4142" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="64.643" y="-32.258" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="12" gate="1" x="63.5" y="-45.72" smashed="yes" rot="R180">
<attribute name="NAME" x="64.643" y="-47.5742" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="64.643" y="-42.418" size="1.778" layer="96" rot="R180"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<wire x1="22.86" y1="76.2" x2="60.96" y2="76.2" width="0.1524" layer="91"/>
<pinref part="IN" gate="-1" pin="S"/>
<label x="27.94" y="76.2" size="1.778" layer="95"/>
<pinref part="CMN" gate="1" pin="P"/>
</segment>
</net>
<net name="1" class="0">
<segment>
<wire x1="22.86" y1="66.04" x2="60.96" y2="66.04" width="0.1524" layer="91"/>
<pinref part="IN" gate="-2" pin="S"/>
<label x="27.94" y="66.04" size="1.778" layer="95"/>
<pinref part="1" gate="1" pin="P"/>
</segment>
</net>
<net name="2" class="0">
<segment>
<wire x1="22.86" y1="55.88" x2="60.96" y2="55.88" width="0.1524" layer="91"/>
<pinref part="IN" gate="-3" pin="S"/>
<label x="27.94" y="55.88" size="1.778" layer="95"/>
<pinref part="2" gate="1" pin="P"/>
</segment>
</net>
<net name="3" class="0">
<segment>
<wire x1="22.86" y1="45.72" x2="60.96" y2="45.72" width="0.1524" layer="91"/>
<pinref part="IN" gate="-4" pin="S"/>
<label x="27.94" y="45.72" size="1.778" layer="95"/>
<pinref part="3" gate="1" pin="P"/>
</segment>
</net>
<net name="4" class="0">
<segment>
<wire x1="22.86" y1="35.56" x2="60.96" y2="35.56" width="0.1524" layer="91"/>
<pinref part="IN" gate="-5" pin="S"/>
<label x="27.94" y="35.56" size="1.778" layer="95"/>
<pinref part="4" gate="1" pin="P"/>
</segment>
</net>
<net name="5" class="0">
<segment>
<wire x1="22.86" y1="25.4" x2="60.96" y2="25.4" width="0.1524" layer="91"/>
<pinref part="IN" gate="-6" pin="S"/>
<label x="27.94" y="25.4" size="1.778" layer="95"/>
<pinref part="5" gate="1" pin="P"/>
</segment>
</net>
<net name="6" class="0">
<segment>
<wire x1="22.86" y1="15.24" x2="60.96" y2="15.24" width="0.1524" layer="91"/>
<pinref part="IN" gate="-7" pin="S"/>
<label x="27.94" y="15.24" size="1.778" layer="95"/>
<pinref part="6" gate="1" pin="P"/>
</segment>
</net>
<net name="7" class="0">
<segment>
<wire x1="22.86" y1="5.08" x2="60.96" y2="5.08" width="0.1524" layer="91"/>
<pinref part="IN" gate="-8" pin="S"/>
<label x="27.94" y="5.08" size="1.778" layer="95"/>
<pinref part="7" gate="1" pin="P"/>
</segment>
</net>
<net name="8" class="0">
<segment>
<wire x1="22.86" y1="-5.08" x2="60.96" y2="-5.08" width="0.1524" layer="91"/>
<pinref part="IN" gate="-9" pin="S"/>
<label x="27.94" y="-5.08" size="1.778" layer="95"/>
<pinref part="8" gate="1" pin="P"/>
</segment>
</net>
<net name="9" class="0">
<segment>
<wire x1="22.86" y1="-15.24" x2="60.96" y2="-15.24" width="0.1524" layer="91"/>
<pinref part="IN" gate="-10" pin="S"/>
<label x="27.94" y="-15.24" size="1.778" layer="95"/>
<pinref part="9" gate="1" pin="P"/>
</segment>
</net>
<net name="10" class="0">
<segment>
<wire x1="22.86" y1="-25.4" x2="60.96" y2="-25.4" width="0.1524" layer="91"/>
<pinref part="IN" gate="-11" pin="S"/>
<label x="27.94" y="-25.4" size="1.778" layer="95"/>
<pinref part="10" gate="1" pin="P"/>
</segment>
</net>
<net name="11" class="0">
<segment>
<wire x1="22.86" y1="-35.56" x2="60.96" y2="-35.56" width="0.1524" layer="91"/>
<pinref part="IN" gate="-12" pin="S"/>
<label x="27.94" y="-35.56" size="1.778" layer="95"/>
<pinref part="11" gate="1" pin="P"/>
</segment>
</net>
<net name="12" class="0">
<segment>
<wire x1="22.86" y1="-45.72" x2="60.96" y2="-45.72" width="0.1524" layer="91"/>
<pinref part="IN" gate="-13" pin="S"/>
<label x="27.94" y="-45.72" size="1.778" layer="95"/>
<pinref part="12" gate="1" pin="P"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
