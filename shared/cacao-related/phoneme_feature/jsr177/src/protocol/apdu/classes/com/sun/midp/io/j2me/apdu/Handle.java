/*
 *   
 *
 * Copyright  1990-2006 Sun Microsystems, Inc. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 only, as published by the Free Software Foundation. 
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License version 2 for more details (a copy is
 * included at /legal/license.txt). 
 * 
 * You should have received a copy of the GNU General Public License
 * version 2 along with this work; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA 
 * 
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa
 * Clara, CA 95054 or visit www.sun.com if you need additional
 * information or have any questions. 
 */

package com.sun.midp.io.j2me.apdu;

import com.sun.midp.security.SecurityToken;

/**
 * This class represents a handle for APDU connection.
 */
public class Handle {

    /** Slot number. */
    int slot;
    /** Logical channel number. */
    public int channel;
    /** CAD object. */
    Cad cad;
    /** Is this connection opened? */
    boolean opened;
    /** Security token used by this connection. */
    public SecurityToken token;
    /** FCI received from selected application. */
    public byte[] FCI;

    /**
     * Unique identifier of card session (period of time between card
     * power up and powerdown) during which the connection was created.
     */
    public int cardSessionId;

    /**
     * Unique identifier of Handle instance.
     * It is used for debugging purposes.
     */
    public int handleInstance;

    /**
     * Counter for handleInstance generation.
     * It is used for debugging purposes.
     */
    private static int instanceNo = 1;
    
    /**
     * Creates a new handle with specified parameters.
     * @param slot slot number
     * @param channel channel number
     * @param token security token
     */
    Handle(int slot, int channel, SecurityToken token) {

        this.slot = slot;
        this.channel = channel;
        this.token = token;
        cad = APDUManager.cads[slot];
        FCI = cad.getFCI();
        opened = true;
        this.cardSessionId = cad.getCardSessionId();
        this.handleInstance = instanceNo++;
    }

    /**
     * Returns ATR of the selected application.
     * @return byte[] ATR.
     */
    public byte[] getATR() {
        return cad.getATR();
    }

    /**
     * Returns FCI of the selected application.
     * @return byte[] FCI.
     */
    public byte[] getFCI() {
        return cad.getFCI();
    }

    /**
     * Returns the card session identifier.
     * This number is different for different card sessions.
     * @return the card session identifier
     */
    public int getCardSessionId() {
        return cad.getCardSessionId();
    }
}
