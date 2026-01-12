import React, { useState, useEffect } from 'react';

const WorstPhoneInput = () => {
    const [phoneNumber, setPhoneNumber] = useState("");
    const [positions, setPositions] = useState(
        Array.from({ length: 10 }, (_, i) => ({
            val: i,
            x: Math.random() * 80,
            y: Math.random() * 80,
            dx: (Math.random() - 0.5) * 2,
            dy: (Math.random() - 0.5) * 2,
        }))
    );

    useEffect(() => {
        const interval = setInterval(() => {
            setPositions(prev => prev.map(p => ({
                ...p,
                x: p.x + p.dx > 90 || p.x + p.dx < 0 ? (p.dx *= -1, p.x) : p.x + p.dx,
                y: p.y + p.dy > 90 || p.y + p.dy < 0 ? (p.dy *= -1, p.y) : p.y + p.dy,
            })));
        }, 50);
        return () => clearInterval(interval);
    }, []);

    const handleDigitClick = (val: number) => {
        setPhoneNumber(prev => prev + val);
    };

    return (
        <div style={{ position: 'relative', height: '100vh', background: '#ff00ff', overflow: 'hidden', cursor: 'wait' }}>
            <h1 style={{ fontFamily: 'Comic Sans MS', color: 'lime' }}>
                Enter Phone Number: {phoneNumber}
            </h1>

            {positions.map((p) => (
                <button
                    key={p.val}
                    onClick={() => handleDigitClick(p.val)}
                    style={{
                        position: 'absolute',
                        left: `${p.x}%`,
                        top: `${p.y}%`,
                        padding: '20px',
                        fontSize: '2rem',
                        borderRadius: '50%',
                        background: 'yellow'
                    }}
                >
                    {p.val}
                </button>
            ))}

            <button
                style={{ position: 'fixed', bottom: 10, right: 10 }}
                onClick={() => { alert("Error: User too slow. Resetting."); setPhoneNumber(""); }}
            >
                Submit (Maybe)
            </button>
        </div>
    );
};

export default WorstPhoneInput;